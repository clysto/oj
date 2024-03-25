# OJ

## `launch.json`

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "OJ Launch",
      "type": "cppdbg",
      "request": "launch",
      "program": "${workspaceFolder}/.build/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "preLaunchTask": "OJ Build",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb"
    }
  ]
}
```

## `tasks.json`

```json
{
  "tasks": [
    {
      "type": "shell",
      "label": "OJ Build",
      "command": "${workspaceFolder}/scripts/build ${file}"
    },
    {
      "type": "shell",
      "label": "OJ Run",
      "command": "${workspaceFolder}/scripts/run ${file} < INPUT",
      "problemMatcher": [],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ],
  "version": "2.0.0"
}
```
