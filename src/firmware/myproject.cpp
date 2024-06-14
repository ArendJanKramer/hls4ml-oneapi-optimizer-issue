#include "myproject.h"
#include "parameters.h"
#include <sycl/ext/intel/experimental/task_sequence.hpp>

// hls-fpga-machine-learning insert weights
#include "weights/w2.h"
#include "weights/b2.h"
#include "weights/w5.h"
#include "weights/b5.h"
#include "weights/w8.h"
#include "weights/b8.h"
#include "weights/w11.h"
#include "weights/b11.h"

// The inter-task pipes need to be declared in the global scope
// hls-fpga-machine-learning insert inter-task pipes

using sycl::ext::intel::experimental::task_sequence;

void Myproject::operator()() const {
    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning read in
    auto fc1_input = Fc1InputPipe::read();

    // hls-fpga-machine-learning declare task sequences

    // hls-fpga-machine-learning insert layers

    [[intel::fpga_register]] layer2_t layer2_out;
    nnet::dense_resource<input_t, layer2_t, config2>(fc1_input, layer2_out, w2, b2);
    [[intel::fpga_register]] layer4_t layer4_out;
    nnet::relu<layer2_t, layer4_t, relu_config4>(layer2_out, layer4_out);
    [[intel::fpga_register]] layer5_t layer5_out;
    nnet::dense_resource<layer4_t, layer5_t, config5>(layer4_out, layer5_out, w5, b5);
    [[intel::fpga_register]] layer7_t layer7_out;
    nnet::relu<layer5_t, layer7_t, relu_config7>(layer5_out, layer7_out);
    [[intel::fpga_register]] layer8_t layer8_out;
    nnet::dense_resource<layer7_t, layer8_t, config8>(layer7_out, layer8_out, w8, b8);
    [[intel::fpga_register]] layer10_t layer10_out;
    nnet::relu<layer8_t, layer10_t, relu_config10>(layer8_out, layer10_out);
    [[intel::fpga_register]] layer11_t layer11_out;
    nnet::dense_resource<layer10_t, layer11_t, config11>(layer10_out, layer11_out, w11, b11);
    [[intel::fpga_register]] result_t layer13_out;
    nnet::softmax<layer11_t, result_t, softmax_config13>(layer11_out, layer13_out);

    // hls-fpga-machine-learning return
    Layer13OutPipe::write(layer13_out);
}
