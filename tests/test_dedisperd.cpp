#include <memory>
#define DEBUG

#include "dedispered.hpp"
#include "filterbank.h"
#include "marcoutils.h"

#include <cstdint>
#include <filesystem>
#include <gtest/gtest.h>
#include <vector>

class TestDedispered : public ::testing::Test {
protected:
  // 获取当前文件所录
  std::filesystem::path current_path = std::filesystem::current_path();
  // 构建测试文件路径
  std::filesystem::path file_path = current_path / "test_file" / "test.fil";
  string file_name = file_path.string();

  void SetUp() override {
    cout << "Test filterbank file path:" << file_name << endl;
  }

  void TearDown() override {}
};

TEST_F(TestDedispered, testDedispered) {
  Filterbank fil(file_name);
  fil.info();
  int time_downsample = 16;
  float dm_low = 0;
  float dm_high = 600;
  float dm_step = 1;
  float t_sample = 0.5f;

  vector<shared_ptr<uint8_t[]>> dm_times =
      dedispered::dedispered_fil_tsample_omp<uint8_t>(
          fil, dm_low, dm_high, dm_step, REF_FREQ_TOP, time_downsample,
          t_sample);

  size_t downsampled_ndata = 20345 / 2 / time_downsample;

  int steps = static_cast<int>((dm_high - dm_low) / dm_step);
  std::vector<size_t> shape = {static_cast<size_t>(steps), downsampled_ndata};

  for (auto dm_time : dm_times) {
    IMSHOW(dm_time.get(), shape);
  }
}
