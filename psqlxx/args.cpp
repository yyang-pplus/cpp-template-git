#include <psqlxx/args.hpp>
#include <psqlxx/version.hpp>


namespace psqlxx {

cxxopts::Options CreateBaseOptions() noexcept {
    cxxopts::Options options("psqlxx", "<Project Description Summary>");

    options.add_options()
    ("h,help", "print usage")
    ("V,version", "print version")
    ;

    return options;
}

void HandleBaseOptions(const cxxopts::Options &options,
                       const cxxopts::ParseResult &parsed_options) noexcept {
    if (parsed_options.count("help")) {
        std::cout << options.help() << std::endl;
        exit(EXIT_SUCCESS);
    }

    if (parsed_options.count("version")) {
        std::cout << "Version: " << GetVersion() << std::endl;
        std::cout << "Git Description: " << GetGitDescribe() << std::endl;
        exit(EXIT_SUCCESS);
    }
}

}//namespace psqlxx
