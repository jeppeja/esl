#include <stdexcept>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../sort_map_s.hpp"
#include <vector>

using namespace testing;
using namespace estl;

class SortMapSUnitTest : public testing::Test
{
public:
    SortMapSUnitTest()  = default;

    ~SortMapSUnitTest() override = default;

    void SetUp() override
    {
    }
    void TearDown() override;

};

void SortMapSUnitTest::TearDown()
{

}

// ----------------------------------------
// --- Simple helper test element class ---
// ----------------------------------------

struct Rect {
    Rect() = default;
    Rect(unsigned w, unsigned h)
        : width_(w),
          height_(h)
    {
    }

    unsigned width_ = 0;
    unsigned height_ = 0;
};


inline bool operator== (const Rect& lhs, const Rect& rhs) {
    return  lhs.width_ == rhs.width_ &&
            lhs.height_ == rhs.height_;
}



// -------------------
// -- Constructors ---
// -------------------

TEST_F(SortMapSUnitTest, default_constructor)
{
    EXPECT_EQ(2, 2);

//     sort_map_s<int, 10> v;
//     EXPECT_TRUE(v.empty());
//     EXPECT_EQ(static_cast<size_t>(0u), v.size());
//     EXPECT_EQ(10u, v.capacity());
//     EXPECT_EQ(10u, v.max_size());
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}