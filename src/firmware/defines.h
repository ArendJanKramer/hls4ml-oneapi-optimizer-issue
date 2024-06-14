#ifndef DEFINES_H_
#define DEFINES_H_

#include <sycl/ext/intel/ac_types/ac_fixed.hpp>
#include <sycl/ext/intel/ac_types/ac_int.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>
#include <sycl/sycl.hpp>

// Include nnet::array - a custom array-like struct, mainly used with io_stream
#include "nnet_utils/nnet_types.h"

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 16
#define N_LAYER_2 64
#define N_LAYER_2 64
#define N_LAYER_5 32
#define N_LAYER_5 32
#define N_LAYER_8 32
#define N_LAYER_8 32
#define N_LAYER_11 5
#define N_LAYER_11 5

// hls-fpga-machine-learning insert layer-precision
typedef nnet::array<ac_fixed<16,6,true>, 16*1> input_t;
typedef ac_fixed<16,6,true> model_default_t;
typedef nnet::array<ac_fixed<16,6,true>, 64*1> layer2_t;
typedef ac_int<1, false> layer2_index;
typedef nnet::array<ac_fixed<16,6,true>, 64*1> layer4_t;
typedef ac_fixed<18,8,true> relu1_table_t;
typedef nnet::array<ac_fixed<16,6,true>, 32*1> layer5_t;
typedef ac_int<1, false> layer5_index;
typedef nnet::array<ac_fixed<16,6,true>, 32*1> layer7_t;
typedef ac_fixed<18,8,true> relu2_table_t;
typedef nnet::array<ac_fixed<16,6,true>, 32*1> layer8_t;
typedef ac_int<1, false> layer8_index;
typedef nnet::array<ac_fixed<16,6,true>, 32*1> layer10_t;
typedef ac_fixed<18,8,true> relu3_table_t;
typedef nnet::array<ac_fixed<16,6,true>, 5*1> layer11_t;
typedef ac_int<1, false> layer11_index;
typedef nnet::array<ac_fixed<16,6,true>, 5*1> result_t;
typedef ac_fixed<18,8,true> softmax_table_t;
typedef ac_fixed<18,8,true,AC_RND,AC_SAT> softmax_exp_table_t;
typedef ac_fixed<18,8,true,AC_RND,AC_SAT> softmax_inv_table_t;

#define DIV_ROUNDUP(n, d) ((n + d - 1) / d)
#define MIN(n, d) (n > d ? d : n)
#define MAX(n, d) (n < d ? d : n)

#endif
