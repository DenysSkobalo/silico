package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"os/exec"
)

func cli() {
	cmd := exec.Command("./build/main")

	stdin, err := cmd.StdinPipe()
	if err != nil {
		panic(err)
	}
	stdout, err := cmd.StdoutPipe()
	if err != nil {
		panic(err)
	}
	scanner := bufio.NewScanner(stdout)

	if err := cmd.Start(); err != nil {
		panic(err)
	}

	io.WriteString(stdin, `{"cmd": "init"}`+"\n")
	io.WriteString(stdin, `{"cmd": "dump"}`+"\n")

	for scanner.Scan() {
		line := scanner.Text()
		// fmt.Println("Raw line:", line)

		var resp map[string]interface{}
		if err := json.Unmarshal([]byte(line), &resp); err != nil {
			fmt.Println("Invalid JSON:", err)
			continue
		}

		if status, ok := resp["status"]; ok {
			fmt.Printf("Init response: status=%v\n", status)
			continue
		}

		if _, ok := resp["x"]; ok {
			fmt.Println("CPU State:")
			fmt.Printf("  PC:     %v\n", resp["pc"])
			fmt.Printf("  SP:     %v\n", resp["sp"])
			fmt.Printf("  EL:     %v\n", resp["current_el"])
			fmt.Printf("  Cycles: %v\n", resp["cycles"])
			fmt.Printf("  Halted: %v\n", resp["halted"])

			if xList, ok := resp["x"].([]interface{}); ok {
				fmt.Print("  X:     ")
				for i, val := range xList {
					fmt.Printf("X%-2d=%-5v ", i, val)
					if (i+1)%4 == 0 {
						fmt.Print("\n         ")
					}
				}
				fmt.Println()
			}

			if pstate, ok := resp["pstate"].(map[string]interface{}); ok {
				fmt.Print("  Flags: ")
				for _, flag := range []string{"N", "Z", "C", "V", "D", "A", "I", "F", "IL", "SS"} {
					fmt.Printf("%s=%v ", flag, pstate[flag])
				}
				fmt.Println()
			}
		}
	}

	_ = cmd.Wait()
}
