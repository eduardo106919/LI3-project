# LI3 Project 2024/2025

This repository contains the implementation for the **LI3 project** of the year 2024/2025.

This project is meant to be "replicate" a **music streaming system**, capable of analysing data and respond to certain queries.

## Build and Execute

To build to the executable, run `make`:

To execute the program, you will have 3 options:
- main program (programa-principal)
- test program (programa-testes)
- interative program (programa-interativo) [on **phase 2 only**]

:warning: To run these executable you must have the csv files and the files with the commands, go to [datasets](/datasets/) and download the necessary items.

**Main** program:
```bash
./bin/programa-principal <dataset-folder> <inputs-file>
```

**Test** program:
```bash
./bin/programa-testes <dataset-folder> <inputs-file> <correct-results-folder>
```

**Interative** program:
```bash
./bin/programa-interativo
```

## Limits

**Phase 1** limits:
- Time: 5 minutes
- Memory: 2 GB

**Phase 2** limits:
- Small dataset:
    - Time: 5 minutes
    - Memory: 2 GB
- Large dataset:
    - Time: 11 minutes
    - Memory: 7GB

You can use the following command in your **terminal** to impuse the memory limits:

```bash
# limit the memory usage by 2 GB
ulimit -m 2048000
```
