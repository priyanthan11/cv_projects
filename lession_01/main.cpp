/**
 * @file main.cpp
 * @brief Lesson 01 - OpenCV Basics: Creating and displaying an image with text
 *
 * Demonstrates fundamental OpenCV concepts:
 *   - Verifying the installed OpenCV version at runtime
 *   - Creating a blank (black) image using cv::Mat
 *   - Drawing text onto an image using cv::putText
 *   - Displaying the result in a named window
 *   - Waiting for a keypress before exiting
 *
 * Build: CMake + MSVC (see CMakeLists.txt)
 * Dependency: OpenCV 4.x installed at C:/opencv/build/install
 */

#include <opencv2/opencv.hpp>  // Main OpenCV header (includes core, highgui, imgproc, etc.)
#include <iostream>

int main() {
    // Print the compile-time OpenCV version - helps confirm the correct
    // library is linked when multiple versions are installed on the machine.
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    /**
     * cv::Mat::zeros(rows, cols, type) allocates a 2D matrix and fills it with 0.
     * A zero-filled CV_8UC3 matrix appears as a solid black image.
     *
     *   300      - height in pixels
     *   300      - width  in pixels
     *   CV_8UC3  - pixel format: 8-bit unsigned, 3 channels (BGR order)
     *
     * cv::Mat uses reference counting, so copies are shallow and memory is freed
     * automatically when the last reference goes out of scope (RAII).
     */
    cv::Mat image = cv::Mat::zeros(300, 300, CV_8UC1);

    /**
     * cv::putText renders a UTF-8 string onto the image in-place.
     *
     *   image                - destination Mat (modified in-place)
     *   "Hello OpenCV!"      - text string to render
     *   cv::Point(30, 150)   - bottom-left origin of the text baseline (x, y)
     *   FONT_HERSHEY_SIMPLEX - clean sans-serif font; other options: ITALIC, COMPLEX, etc.
     *   1.0                  - font scale multiplier (1.0 = default size ~30px tall)
     *   cv::Scalar(0, 0, 255)- pixel colour in BGR order -> pure red
     *                          (OpenCV stores channels as Blue-Green-Red, not RGB)
     *   2                    - stroke thickness in pixels
     */
    cv::putText(image,
                "Hello OpenCV!",
                cv::Point(30, 150),
                cv::FONT_HERSHEY_SIMPLEX,
                1.0,
                cv::Scalar(255, 0, 255),  // Red in BGR (B=0, G=0, R=255)
                2);

    /**
     * cv::imshow(windowName, image) opens a named GUI window and renders the Mat.
     * The window stays open until cv::waitKey or cv::destroyAllWindows is called.
     */
    cv::imshow("Lesson 01", image);

    /**
     * cv::waitKey(delay) pumps the GUI event loop and waits for a key event.
     *   delay = 0  -> block indefinitely until any key is pressed
     *   delay > 0  -> wait at most 'delay' milliseconds, then continue
     *
     * Returns the ASCII code of the pressed key, or -1 on timeout.
     * Must be called after imshow for the window to actually paint.
     */
    cv::waitKey(0);

    return 0;
}
