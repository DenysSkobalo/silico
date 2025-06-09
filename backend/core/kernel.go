package core

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"os/exec"
)

type Kernel struct {
	stdin  io.WriteCloser
	stdout *bufio.Scanner
	cmd    *exec.Cmd
}

func NewKernel() (*Kernel, error) {
	cmd := exec.Command("./../build/main")
	stdin, err := cmd.StdinPipe()
	if err != nil {
		return nil, err
	}
	stdoutPipe, err := cmd.StdoutPipe()
	if err != nil {
		return nil, err
	}
	
	scanner := bufio.NewScanner(stdoutPipe)
	if err := cmd.Start(); err != nil {
		return nil, err
	}

	return &Kernel{stdin: stdin, stdout: scanner, cmd: cmd}, nil
}

func (k *Kernel) SendCommand(cmd string) (map[string]interface{}, error) {
	_, err := io.WriteString(k.stdin, cmd+"\n")
	if err != nil {
		return nil, err
	}

	for k.stdout.Scan() {
		line := k.stdout.Text()
		var resp map[string]interface{}
		if err := json.Unmarshal([]byte(line), &resp); err != nil {
			continue // skip non-JSON lines
		}
		return resp, nil
	}
	return nil, fmt.Errorf("no response")
}
