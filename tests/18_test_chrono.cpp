#include <gtest/gtest.h>
#include <chrono>
TEST(ChronoTest, Seconds)
{
    using namespace std::chrono_literals;
    const std::chrono::duration<int> thirty_seconds_to_mars{30};
    EXPECT_EQ(thirty_seconds_to_mars, 30s);
}

TEST(ChronoTest, MilliSeconds)
{
    using namespace std::chrono_literals;
    const std::chrono::duration<int, std::milli> duration{1000};
    EXPECT_EQ(duration, 1000ms);
}

TEST(ChronoTest, Hours){
    using namespace std::chrono_literals;
    const std::chrono::duration<int, std::ratio<3600,1>> fourty_eight_hours{48};
    EXPECT_EQ(fourty_eight_hours, 48h);
}
TEST(ChronoTest, Minutes){
    using namespace std::chrono_literals;
    const std::chrono::duration<int, std::ratio<60,1>> eighty_eight_minutes{88};
    EXPECT_EQ(eighty_eight_minutes, 88min);
}
TEST(ChronotTest, Duration) {
    using namespace std::chrono_literals;
    const auto start = std::chrono::high_resolution_clock::now();

    std::this_thread::sleep_for(2s);

    const auto stop = std::chrono::high_resolution_clock::now();
    const auto diff = stop - start;
    EXPECT_GE(diff, 2000ms);

}

