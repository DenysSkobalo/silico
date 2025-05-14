package main
/*
#cgo CFLAGS: -I../../../kernel/include
#cgo LDFLAGS: -L../../../build -lkernel
#include "cpu.h"
#include "utils.h"
uint32_t get_cpsr_value(ARM_CPU *cpu);
*/
import "C"

import (
    "encoding/json"
    "net/http"
    "log"
)

type CPUResponse struct {
    R0   uint32 `json:"r0"`
    SP   uint32 `json:"sp"`
    PC   uint32 `json:"pc"`
    CPSR uint32 `json:"cpsr"`
}

func cpuHandler(w http.ResponseWriter, r *http.Request) {
    cpu := C.init_cpu()
    resp := CPUResponse{
        R0:   uint32(cpu.R0.value),
        SP:   uint32(cpu.SP.value),
        PC:   uint32(cpu.PC.value),
        CPSR: uint32(C.get_cpsr_value(&cpu)),
    }

    json.NewEncoder(w).Encode(resp)
}

func main() {
    http.HandleFunc("/cpu", cpuHandler)
    log.Println("Server running on http://localhost:8080")
    http.ListenAndServe(":8080", nil)
}