# custom_memory

## Overview

This project showcases an example implementation of a custom memory allocator. The primary goal is to manage memory without relying on existing implementations.

## Advantages

- Avoid heap usage or linking to the CRT library on Windows.
- Avoid calling Windows API functions.
- All allocations and deallocations within your application can be redirected to the custom allocators.

## Limitations

- **Not Production-Ready:** This implementation is for educational purposes and is not suitable for use in production environments.
- **Lack of Optimization:** The allocator has not been tested or built with performance as a priority.
- **Not Thread-Safe:** This example is not designed to be thread-safe and will likely have issues in multi-threaded environments.

## Reference

[mtrebi/memory-allocators](https://github.com/mtrebi/memory-allocators).
