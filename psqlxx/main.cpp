#include <psqlxx/args.hpp>


using namespace psqlxx;


namespace {

[[nodiscard]]
inline auto buildOptions() noexcept {
    auto options = CreateBaseOptions();

    return options;
}

[[nodiscard]]
inline auto
handleOptions(cxxopts::Options &options, const int argc, const char *argv[]) noexcept {
    const auto results = [&]() {
        try {
            return options.parse(argc, argv);
        } catch (const cxxopts::option_not_exists_exception &e) {
            std::cerr << e.what() << std::endl;
        } catch (const cxxopts::OptionException &e) {
            std::cerr << e.what() << std::endl;
        }
        exit(EXIT_FAILURE);
    }
    ();

    HandleBaseOptions(options, results);
}

[[nodiscard]]
inline constexpr auto toExitCode(const bool success) noexcept {
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}

}


int main(int argc, const char *argv[]) {
    auto options = buildOptions();

    handleOptions(options, argc, argv);
}
