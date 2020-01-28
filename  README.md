# PK PRiR Project
Application use OpenCV and work on video input to apply some filters.

Not Concurent Algorithm implementation:

- Black and white
- Sepia
- Blur
- Contrast
- Edge detection

## Getting Started

To check app work run:

```bash
./run.sh
```


### Prerequisites

To compile this app you need `CMake` and `OpenCV 4`  

```bash
./build.sh
```

output aplication `cmake-build-debug/video-filter-sequential`

run parametr:

`video-filter-sequential [video input] [filtr] [preview flag]`

`[filtr]`:

- `kontrast` - Contrast
- `sepia` - Sepia
- `czarno-bialy` - Black and white
- `rozmycie` - Blur
- `wykrywanie-krawedzi` - Edge detection

`[preview flag]` - `wyswietlaj` flag show preview window use opencv `imshow`

## Authors

* **Ireneusz Kuliga** - [Driblinho](https://github.com/Driblinho)
* **Jarosław Kuliga** - [DelPiero10pl](https://github.com/DelPiero10pl)
