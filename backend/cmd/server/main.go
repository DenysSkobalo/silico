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
    "log"

    "github.com/gofiber/fiber/v2"
    "github.com/gofiber/websocket/v2"
)

type CPUResponse struct {
    R  [16]uint32 `json:"r"`
    CPSRFlags struct {
        N    uint32 `json:"n"`
        Z    uint32 `json:"z"`
        C    uint32 `json:"c"`
        V    uint32 `json:"v"`
        Q    uint32 `json:"q"`
        I    uint32 `json:"i"`
        F    uint32 `json:"f"`
        T    uint32 `json:"t"`
        MODE uint32 `json:"mode"`
    } `json:"cpsr_flags"`
}

func cpuInitHandler(c *websocket.Conn) {
    for {
        messageType, msg, err := c.ReadMessage()
        if err != nil {
            log.Println("read error:", err)
            break
        }

        if messageType == websocket.TextMessage && string(msg) == "init_cpu" {
            cpu := C.init_cpu()

            resp := CPUResponse{}
            for i := 0; i < 16; i++ {
                resp.R[i] = uint32(cpu.R[i].value)
            }

            cpsr := uint32(C.get_cpsr_value(&cpu))
            resp.CPSRFlags.N = (cpsr >> 31) & 1
            resp.CPSRFlags.Z = (cpsr >> 30) & 1
            resp.CPSRFlags.C = (cpsr >> 29) & 1
            resp.CPSRFlags.V = (cpsr >> 28) & 1
            resp.CPSRFlags.Q = (cpsr >> 27) & 1
            resp.CPSRFlags.I = (cpsr >> 7) & 1
            resp.CPSRFlags.F = (cpsr >> 6) & 1
            resp.CPSRFlags.T = (cpsr >> 5) & 1
            resp.CPSRFlags.MODE = cpsr & 0x1F

            response, _ := json.Marshal(resp)
            if err := c.WriteMessage(websocket.TextMessage, response); err != nil {
                log.Println("write error:", err)
                break
            }
        }
    }
}

func main() {
    app := fiber.New()

    app.Get("/ws", websocket.New(cpuInitHandler))

    log.Println("WebSocket server running on ws://localhost:8080/ws")
    log.Fatal(app.Listen(":8080"))
}