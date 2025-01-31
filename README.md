# Filterbank Dedispersion Toolkit

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)

A high-performance C++ library for radio astronomy signal processing, specializing in filterbank data dedispersion.

## ✨ Features

- **Efficient Dedispersion**: Process radio telescope data with optimized algorithms
- **Parallel Processing**: Multi-threaded and OpenMP implementations
- **Flexible Configuration**:
  - Customizable DM ranges and steps
  - Time downsampling support
  - Reference frequency selection
- **Modern C++**: Utilizes C++17 features for clean and maintainable code

## 🚀 Quick Start

```cpp
#include "filterbank.h"
#include "dedispered.hpp"

int main() {
    Filterbank fil("observation.fil");
    auto results = dedispered::dedispered_fil_tsample<float>(
        fil, 0.0, 100.0, 0.1, REF_FREQ_TOP, 64, 0.5);
    // Process results...
}
```

## 📚 Documentation

### Core Classes

- **Filterbank**: Handles filterbank file I/O and metadata
- **dedispered**: Namespace containing dedispersion algorithms

### Key Functions

```cpp
template <typename T>
std::vector<std::shared_ptr<T[]>> dedispered_fil_tsample(
    Filterbank &fil, 
    float dm_low, 
    float dm_high,
    float dm_step = 1,
    int ref_freq = REF_FREQ_TOP,
    int time_downsample = 64,
    float t_sample = 0.5);
```

## 📦 Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/filterbank-dedispersion.git
   cd filterbank-dedispersion
   ```

2. Build with CMake:

   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

## 🤝 Contributing

Contributions are welcome! Please see our [contribution guidelines](CONTRIBUTING.md).

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Made with ❤️ by [Your Name] | [GitHub](https://github.com/yourusername)
