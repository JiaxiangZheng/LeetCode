package main

import (
    "fmt"
    "os"
    "io"
    "bufio"
    "strconv"
    "regexp"
    "strings"
)

func main() {
    f, err := os.Open("list.txt")
    if err != nil {
        os.Exit(-1)
    }
    reader := bufio.NewReader(f)
    reg := regexp.MustCompile(`\s`)
    for  {
        line, _, err := reader.ReadLine()
        if err != nil {
            if err == io.EOF {; break; };
            os.Exit(-1)
        }
        strs := strings.Split(string(line), ";")
        index, err := strconv.Atoi(strs[0])
        if err != nil {
            os.Exit(-1)
        }
        strs[0] = fmt.Sprintf("%03d", index)
        srcName := strs[0] + ".cpp"
        strs[1] = strings.ToLower(strs[1])
        strs[1] = reg.ReplaceAllLiteralString(strs[1], "-")
        newName := fmt.Sprintf("%s-%s.cpp", strs[0], strs[1])

        err = os.Rename(srcName, newName)
        info := "success"
        if err != nil {
            info = "failed"
        }
        fmt.Printf("rename %s \t %s\t %s\n", info, srcName, newName)
    }
    return
}
