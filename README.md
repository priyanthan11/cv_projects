# OpenCV Learning Journey — C++

A series of hands-on OpenCV lessons written in C++, building core computer vision skills from image I/O through contour detection.

## Prerequisites

| Tool | Version |
|------|---------|
| OpenCV | 4.x (installed at `C:/opencv/build/install`) |
| CMake | 3.10+ |
| MSVC | C++20 |

## Project Structure

```
cv_projects/
├── lesson_01/   Image loading, display, and basic properties
├── lession_02/  Grayscale conversion and image inspection
├── lesson_03/   Resize and safe crop with ROI clamping
├── lesson_04/   Pixel access, Gaussian blur, Canny edge detection
└── lesson_05/   Contour detection and bounding boxes
```

## Building a Lesson

Each lesson is a self-contained CMake project.

```bash
cd lesson_0X
cmake -B build
cmake --build build --config Release
./build/Release/lesson_0X.exe
```

---

## Lessons

### Lesson 01 — Image Loading & Display
**Concepts:** `cv::imread`, `cv::imshow`, `cv::waitKey`, `cv::Mat` properties

Loads an image from disk, prints its dimensions and channel count, and displays it in a window.

---

### Lesson 02 — Grayscale Conversion & Inspection
**Concepts:** `cv::cvtColor`, `COLOR_BGR2GRAY`, channel inspection

Converts a colour image to grayscale and inspects pixel data and matrix metadata.

---

### Lesson 03 — Resize & Safe Crop
**Concepts:** `cv::resize`, `cv::Rect`, ROI clamping with `&=`

Resizes an image to a target resolution, then crops a region of interest.
The ROI is clamped to the image boundaries before cropping — preventing out-of-bounds access when the requested region extends past the edge of the image.

```
Original Size:  W x H
Resized Size:   640 x 400
Clamped ROI:    x, y, width, height
```

---

### Lesson 04 — Pixel Access, Blur & Edge Detection
**Concepts:** `cv::Vec3b`, `cv::GaussianBlur`, `cv::Canny`, `cv::cvtColor`

Three operations on a resized image:

1. **Pixel access** — reads the BGR values at a specific coordinate using `Mat::at<Vec3b>`.
2. **Gaussian blur** — smooths the image with a 15×15 kernel to reduce noise.
3. **Canny edge detection** — converts to grayscale, then detects edges with low/high thresholds of 10/50.

Displays three windows: original, blurred, and edges.

---

### Lesson 05 — Contour Detection & Bounding Boxes
**Concepts:** `cv::findContours`, `cv::drawContours`, `cv::boundingRect`, `cv::dilate`, `cv::putText`

Full contour-detection pipeline:

1. Convert to grayscale → Gaussian blur (3×3) → Canny edges (threshold 25/25).
2. Dilate the edge map (2 iterations) to connect nearby gaps.
3. Find external contours with `RETR_EXTERNAL` + `CHAIN_APPROX_SIMPLE`.
4. Filter by area (> 1000 px²), then for each qualifying contour:
   - Draw the contour outline in green.
   - Draw a blue bounding rectangle.
   - Label the rectangle with its pixel area.

Prints contour count and per-contour area to stdout.

```
Contours found: N
Contour 0 area: 12345
...
Contours drawn: M
```
