package main

import (
	"encoding/json"
	"log"
	"net/http"
	"silico/core"
)

var kernel *core.Kernel

func main() {
	var err error
	kernel, err = core.NewKernel()
	if err != nil {
		log.Fatalf("Failed to start kernel process: %v", err)
	}

	http.HandleFunc("/init", handleInit)
	http.HandleFunc("/dump", handleDump)
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.URL.Path != "/" {
			http.NotFound(w, r)
			return
		}
		http.ServeFile(w, r, "./public/index.html")
	})

	log.Println("Server listening on http://localhost:8080")
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func handleInit(w http.ResponseWriter, r *http.Request) {
	resp, err := kernel.SendCommand(`{"cmd": "init"}`)
	if err != nil {
		http.Error(w, "failed to init", 500)
		return
	}
	json.NewEncoder(w).Encode(resp)
}

func handleDump(w http.ResponseWriter, r *http.Request) {
	resp, err := kernel.SendCommand(`{"cmd": "dump"}`)
	if err != nil {
		http.Error(w, "failed to dump", 500)
		return
	}
	json.NewEncoder(w).Encode(resp)
}
