#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
    // 检查命令行参数是否正确
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];  // 输入文件名
    std::string output_file = argv[2]; // 输出文件名

    // 构建 ffmpeg 命令
    std::string command = "ffmpeg -i " + input_file +
                          " -c:v rawvideo -pix_fmt yuv420p " + output_file;

    // 执行命令
    std::cout << "Converting " << input_file << " to " << output_file << " in YUV format..." << std::endl;
    if (system(command.c_str()) != 0) {
        std::cerr << "Failed to convert the file." << std::endl;
        return -1;
    }

    std::cout << "Conversion successful: " << output_file << std::endl;
    return 0;
}

