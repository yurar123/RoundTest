// RoundTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int rounding(int input)
{
    int absInput = std::abs(input);
    int hrn = absInput / 100;
    int kop = absInput % 100;
    int rounded = 0;

    if (kop >= 1 && kop <= 24)
        rounded = hrn * 100;
    else if ((kop >= 25 && kop <= 49) || (kop >= 51 && kop <= 74))
        rounded = hrn * 100 + 50;
    else if (kop == 0 || kop == 50)
        rounded = hrn * 100 + kop;
    else if (kop >= 75 && kop <= 99)
        rounded = (hrn + 1) * 100;

    // Preserve sign
    if (input < 0)
        rounded = -rounded;

    return rounded - input;
}

void run_tests()
{
    struct TestCase {
        int input;
        int expected;
    };

    TestCase testCases[] = {
        {400, 0},
        {414, -14},
        {425, 25},
        {427, 23},
        {450, 0},
        {452, -2},
        {475, 25},
        {480, 20},
        {500, 0},
        {-400, 0},
        {-414, 14},
        {-425, -25},
        {-427, -23},
        {-450, 0},
        {-452, 2},
        {-475, -25},
        {-480, -20},
        {-500, 0}
    };

    bool allPassed = true;
    for (const auto& test : testCases) {
        int result = rounding(test.input);
        if (result != test.expected) {
            std::cout << "Test failed for input " << test.input
                << ": expected " << test.expected
                << ", got " << result << std::endl;
            allPassed = false;
        }
    }
    if (allPassed) {
        std::cout << "All tests passed!" << std::endl;
    }
}

int main()
{
	std::cout << "Input: " << 400 << " Output: " << rounding(400) << std::endl; // Expected output: 0
	std::cout << "Input: " << 414 << " Output: " << rounding(414) << std::endl; // Expected output: -14
	std::cout << "Input: " << 425 << " Output: " << rounding(425) << std::endl; // Expected output: 25
	std::cout << "Input: " << 427 << " Output: " << rounding(427) << std::endl; // Expected output: 23
	std::cout << "Input: " << 450 << " Output: " << rounding(450) << std::endl; // Expected output: 0
	std::cout << "Input: " << 452 << " Output: " << rounding(452) << std::endl; // Expected output: -2
	std::cout << "Input: " << 475 << " Output: " << rounding(475) << std::endl; // Expected output: 25
	std::cout << "Input: " << 480 << " Output: " << rounding(480) << std::endl; // Expected output: 20
	std::cout << "Input: " << 500 << " Output: " << rounding(500) << std::endl; // Expected output: 0
	std::cout << "Input: " << -400 << " Output: " << rounding(-400) << std::endl; // Expected output: 0
	std::cout << "Input: " << -414 << " Output: " << rounding(-414) << std::endl; // Expected output: 14
	std::cout << "Input: " << -425 << " Output: " << rounding(-425) << std::endl; // Expected output: -25
	std::cout << "Input: " << -427 << " Output: " << rounding(-427) << std::endl; // Expected output: -23
	std::cout << "Input: " << -450 << " Output: " << rounding(-450) << std::endl; // Expected output: 0
	std::cout << "Input: " << -452 << " Output: " << rounding(-452) << std::endl; // Expected output: 2
	std::cout << "Input: " << -475 << " Output: " << rounding(-475) << std::endl; // Expected output: -25
	std::cout << "Input: " << -480 << " Output: " << rounding(-480) << std::endl; // Expected output: -20
	std::cout << "Input: " << -500 << " Output: " << rounding(-500) << std::endl; // Expected output: 0

    run_tests();

	return 0;
}
