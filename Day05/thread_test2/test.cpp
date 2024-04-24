#include <iostream>
#include <thread>

int current_download_size = 0;

int full_file_size = 100;

void download_file(float *rate_progress)
{
    while (current_download_size <= 100)
    {
        current_download_size += 10;
        *rate_progress = (float)current_download_size / (float)full_file_size;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "download_file end\n";
}

int main()
{
    float rate_progress = 0;
    std::thread t1(download_file, &rate_progress);

    while (current_download_size <= 100)
    {
        std::cout << "rate_progress:" << rate_progress << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    t1.join();

    return 0;
}