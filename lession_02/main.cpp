/**
 * @file main.cpp
 * @brief Lesson 02 - Loading, inspecting, and converting images with OpenCV
 *
 * This program covers the next set of fundamental OpenCV operations:
 *   - Reading an image from disk with cv::imread
 *   - Validating that the load succeeded (empty-check)
 *   - Inspecting image metadata: width, height, channels, type
 *   - Converting a colour (BGR) image to grayscale with cv::cvtColor
 *   - Displaying multiple windows simultaneously with cv::imshow
 *   - Saving a processed image to disk with cv::imwrite
 *
 * Build: CMake + MSVC (see CMakeLists.txt)
 * Dependency: OpenCV 4.x installed at C:/opencv/build/install
 */

#include <opencv2/opencv.hpp>  // Includes core, imgcodecs, imgproc, highgui, etc.
#include <iostream>

int main()
{
    // Print the compile-time OpenCV version so we can confirm which
    // library version is actually linked at runtime.
    std::cout << "OpenCV Version: " << CV_VERSION << std::endl;

    /**
     * cv::imread(path, flags) decodes an image file into a cv::Mat.
     *
     *   path   - absolute or relative path to the image file.
     *            Supported formats: JPEG, PNG, BMP, TIFF, WebP, etc.
     *   flags  - (optional, default = IMREAD_COLOR)
     *            IMREAD_COLOR     -> 3-channel BGR  (ignores alpha)
     *            IMREAD_GRAYSCALE -> 1-channel gray
     *            IMREAD_UNCHANGED -> keeps alpha channel if present
     *
     * Returns an empty Mat if the file does not exist or cannot be decoded.
     * Always check .empty() before using the result.
     */
    cv::Mat image = cv::imread("C:\\___C++\\1. C++\\cv_projects\\lession_02\\test.jpg");

    // Guard: imread returns an empty Mat on failure (wrong path, bad format, etc.).
    // Exiting early with -1 signals an error to the calling process / shell.
    if (image.empty())
    {
        std::cout << "Error: Could not load image." << std::endl;
        return -1;
    }

    std::cout << "Image Loaded Successfully." << std::endl;

    /**
     * cv::Mat exposes image geometry and format via member fields:
     *
     *   .cols      - width  in pixels  (number of columns)
     *   .rows      - height in pixels  (number of rows)
     *   .channels()- number of colour channels (1 = gray, 3 = BGR, 4 = BGRA)
     *   .type()    - combined depth + channel code (e.g. CV_8UC3 = 16)
     *                Use cv::typeToString(image.type()) for a human-readable label.
     */
    std::cout << "Width: "    << image.cols       << std::endl;
    std::cout << "Height: "   << image.rows       << std::endl;
    std::cout << "Channels: " << image.channels() << std::endl;
    std::cout << "Type: "     << image.type()     << std::endl;

    /**
     * cv::cvtColor(src, dst, code) converts the colour space of 'src' and
     * writes the result into 'dst' (allocated automatically).
     *
     *   src                  - input Mat  (BGR, 3-channel, CV_8UC3)
     *   gray                 - output Mat (will become 1-channel, CV_8UC1)
     *   cv::COLOR_BGR2GRAY   - conversion code: weighted sum of B, G, R channels
     *                          using the ITU-R BT.601 formula:
     *                          Y = 0.114*B + 0.587*G + 0.299*R
     *
     * After this call, 'gray' is a completely independent Mat (deep copy).
     */
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Confirm the grayscale Mat has 1 channel and type CV_8UC1 (value = 0).
    std::cout << "Gray Channels: " << gray.channels() << std::endl;
    std::cout << "Gray Type: "     << gray.type()     << std::endl;

    /**
     * cv::imshow(windowName, mat) creates (or reuses) a named window and
     * renders the Mat inside it. Calling it with two different names opens
     * two independent windows side by side.
     *
     * Note: both imshow calls queue paint requests; cv::waitKey below
     *       drives the event loop that actually paints them on screen.
     */
    cv::imshow("Lession 02", image);   // Original colour image
    cv::imshow("Gray Image", gray);    // Grayscale version

    /**
     * cv::imwrite(path, mat) encodes the Mat and writes it to disk.
     * The output format is inferred from the file extension (.jpg -> JPEG).
     *
     *   "gray_output.jpg" - saved to the current working directory
     *                       (the directory from which the executable is run).
     *
     * Returns true on success, false on failure (e.g. bad path or bad format).
     */
    cv::imwrite("gray_output.jpg", gray);
    std::cout << "Gray Image saved." << std::endl;

    /**
     * cv::waitKey(0) pumps the GUI event loop and waits indefinitely until
     * any key is pressed. Required for imshow windows to remain visible.
     */
    cv::waitKey(0);

    return 0;
}
