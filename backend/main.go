package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"os/exec"
)

func main() {
	cmd := exec.Command("./build/main")

	stdin, err := cmd.StdinPipe()
	if err != nil {
		panic(err)
	}

	stdout, err := cmd.StdoutPipe()
	if err != nil {
		panic(err)
	}

	if err := cmd.Start(); err != nil {
		panic(err)
	}

	_, _ = io.WriteString(stdin, `{"cmd": "init"}`+"\n")

	scanner := bufio.NewScanner(stdout)

	for scanner.Scan() {
		var initRes map[string]interface{}
		err := json.Unmarshal(scanner.Bytes(), &initRes)
		if err != nil {
			fmt.Println("Invalid JSON from `init`:", scanner.Text())
			continue
		}
		fmt.Println("`init` response:", initRes)
		break
	}

	_, _ = io.WriteString(stdin, `{"cmd": "dump"}`+"\n")

	if scanner.Scan() {
		var dump map[string]interface{}
		err := json.Unmarshal(scanner.Bytes(), &dump)
		if err != nil {
			fmt.Println("Invalid JSON from dump:", scanner.Text())
		} else {
			fmt.Println("CPU Dump:")
			fmt.Printf("  PC: %v\n", dump["pc"])
			fmt.Printf("  SP: %v\n", dump["sp"])
			fmt.Printf("  X:  %v\n", dump["x"])
			fmt.Printf("  Flags: %v\n", dump["pstate"])
			fmt.Printf("  EL:    %v\n", dump["current_el"])
			fmt.Printf("  Cycles: %v\n", dump["cycles"])
			fmt.Printf("  Halted: %v\n", dump["halted"])
		}
	}

	_ = cmd.Wait()
}
