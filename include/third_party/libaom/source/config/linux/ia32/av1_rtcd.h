#ifndef AV1_RTCD_H_
#define AV1_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * AV1
 */

#include "aom/aom_integer.h"
#include "aom_dsp/txfm_common.h"
#include "av1/common/av1_txfm.h"
#include "av1/common/common.h"
#include "av1/common/convolve.h"
#include "av1/common/enums.h"
#include "av1/common/filter.h"
#include "av1/common/odintrin.h"
#include "av1/common/quant_common.h"

struct macroblockd;

/* Encoder forward decls */
struct macroblock;
struct txfm_param;
struct aom_variance_vtable;
struct search_site_config;
struct mv;
union int_mv;
struct yv12_buffer_config;

#ifdef __cplusplus
extern "C" {
#endif

void aom_clpf_block_c(uint8_t* dst,
                      const uint16_t* src,
                      int dstride,
                      int sstride,
                      int sizex,
                      int sizey,
                      unsigned int strength,
                      unsigned int bd);
void aom_clpf_block_sse2(uint8_t* dst,
                         const uint16_t* src,
                         int dstride,
                         int sstride,
                         int sizex,
                         int sizey,
                         unsigned int strength,
                         unsigned int bd);
void aom_clpf_block_ssse3(uint8_t* dst,
                          const uint16_t* src,
                          int dstride,
                          int sstride,
                          int sizex,
                          int sizey,
                          unsigned int strength,
                          unsigned int bd);
void aom_clpf_block_sse4_1(uint8_t* dst,
                           const uint16_t* src,
                           int dstride,
                           int sstride,
                           int sizex,
                           int sizey,
                           unsigned int strength,
                           unsigned int bd);
RTCD_EXTERN void (*aom_clpf_block)(uint8_t* dst,
                                   const uint16_t* src,
                                   int dstride,
                                   int sstride,
                                   int sizex,
                                   int sizey,
                                   unsigned int strength,
                                   unsigned int bd);

void aom_clpf_block_hbd_c(uint16_t* dst,
                          const uint16_t* src,
                          int dstride,
                          int sstride,
                          int sizex,
                          int sizey,
                          unsigned int strength,
                          unsigned int bd);
void aom_clpf_block_hbd_sse2(uint16_t* dst,
                             const uint16_t* src,
                             int dstride,
                             int sstride,
                             int sizex,
                             int sizey,
                             unsigned int strength,
                             unsigned int bd);
void aom_clpf_block_hbd_ssse3(uint16_t* dst,
                              const uint16_t* src,
                              int dstride,
                              int sstride,
                              int sizex,
                              int sizey,
                              unsigned int strength,
                              unsigned int bd);
void aom_clpf_block_hbd_sse4_1(uint16_t* dst,
                               const uint16_t* src,
                               int dstride,
                               int sstride,
                               int sizex,
                               int sizey,
                               unsigned int strength,
                               unsigned int bd);
RTCD_EXTERN void (*aom_clpf_block_hbd)(uint16_t* dst,
                                       const uint16_t* src,
                                       int dstride,
                                       int sstride,
                                       int sizex,
                                       int sizey,
                                       unsigned int strength,
                                       unsigned int bd);

void aom_clpf_hblock_c(uint8_t* dst,
                       const uint16_t* src,
                       int dstride,
                       int sstride,
                       int sizex,
                       int sizey,
                       unsigned int strength,
                       unsigned int bd);
void aom_clpf_hblock_sse2(uint8_t* dst,
                          const uint16_t* src,
                          int dstride,
                          int sstride,
                          int sizex,
                          int sizey,
                          unsigned int strength,
                          unsigned int bd);
void aom_clpf_hblock_ssse3(uint8_t* dst,
                           const uint16_t* src,
                           int dstride,
                           int sstride,
                           int sizex,
                           int sizey,
                           unsigned int strength,
                           unsigned int bd);
void aom_clpf_hblock_sse4_1(uint8_t* dst,
                            const uint16_t* src,
                            int dstride,
                            int sstride,
                            int sizex,
                            int sizey,
                            unsigned int strength,
                            unsigned int bd);
RTCD_EXTERN void (*aom_clpf_hblock)(uint8_t* dst,
                                    const uint16_t* src,
                                    int dstride,
                                    int sstride,
                                    int sizex,
                                    int sizey,
                                    unsigned int strength,
                                    unsigned int bd);

void aom_clpf_hblock_hbd_c(uint16_t* dst,
                           const uint16_t* src,
                           int dstride,
                           int sstride,
                           int sizex,
                           int sizey,
                           unsigned int strength,
                           unsigned int bd);
void aom_clpf_hblock_hbd_sse2(uint16_t* dst,
                              const uint16_t* src,
                              int dstride,
                              int sstride,
                              int sizex,
                              int sizey,
                              unsigned int strength,
                              unsigned int bd);
void aom_clpf_hblock_hbd_ssse3(uint16_t* dst,
                               const uint16_t* src,
                               int dstride,
                               int sstride,
                               int sizex,
                               int sizey,
                               unsigned int strength,
                               unsigned int bd);
void aom_clpf_hblock_hbd_sse4_1(uint16_t* dst,
                                const uint16_t* src,
                                int dstride,
                                int sstride,
                                int sizex,
                                int sizey,
                                unsigned int strength,
                                unsigned int bd);
RTCD_EXTERN void (*aom_clpf_hblock_hbd)(uint16_t* dst,
                                        const uint16_t* src,
                                        int dstride,
                                        int sstride,
                                        int sizex,
                                        int sizey,
                                        unsigned int strength,
                                        unsigned int bd);

void av1_convolve_2d_c(const uint8_t* src,
                       int src_stride,
                       CONV_BUF_TYPE* dst,
                       int dst_stride,
                       int w,
                       int h,
                       InterpFilterParams* filter_params_x,
                       InterpFilterParams* filter_params_y,
                       const int subpel_x_q4,
                       const int subpel_y_q4,
                       ConvolveParams* conv_params);
void av1_convolve_2d_sse2(const uint8_t* src,
                          int src_stride,
                          CONV_BUF_TYPE* dst,
                          int dst_stride,
                          int w,
                          int h,
                          InterpFilterParams* filter_params_x,
                          InterpFilterParams* filter_params_y,
                          const int subpel_x_q4,
                          const int subpel_y_q4,
                          ConvolveParams* conv_params);
RTCD_EXTERN void (*av1_convolve_2d)(const uint8_t* src,
                                    int src_stride,
                                    CONV_BUF_TYPE* dst,
                                    int dst_stride,
                                    int w,
                                    int h,
                                    InterpFilterParams* filter_params_x,
                                    InterpFilterParams* filter_params_y,
                                    const int subpel_x_q4,
                                    const int subpel_y_q4,
                                    ConvolveParams* conv_params);

void av1_convolve_2d_scale_c(const uint8_t* src,
                             int src_stride,
                             CONV_BUF_TYPE* dst,
                             int dst_stride,
                             int w,
                             int h,
                             InterpFilterParams* filter_params_x,
                             InterpFilterParams* filter_params_y,
                             const int subpel_x_qn,
                             const int x_step_qn,
                             const int subpel_y_q4,
                             const int y_step_qn,
                             ConvolveParams* conv_params);
#define av1_convolve_2d_scale av1_convolve_2d_scale_c

void av1_convolve_horiz_c(const uint8_t* src,
                          int src_stride,
                          uint8_t* dst,
                          int dst_stride,
                          int w,
                          int h,
                          const InterpFilterParams fp,
                          const int subpel_x_q4,
                          int x_step_q4,
                          ConvolveParams* conv_params);
void av1_convolve_horiz_ssse3(const uint8_t* src,
                              int src_stride,
                              uint8_t* dst,
                              int dst_stride,
                              int w,
                              int h,
                              const InterpFilterParams fp,
                              const int subpel_x_q4,
                              int x_step_q4,
                              ConvolveParams* conv_params);
RTCD_EXTERN void (*av1_convolve_horiz)(const uint8_t* src,
                                       int src_stride,
                                       uint8_t* dst,
                                       int dst_stride,
                                       int w,
                                       int h,
                                       const InterpFilterParams fp,
                                       const int subpel_x_q4,
                                       int x_step_q4,
                                       ConvolveParams* conv_params);

void av1_convolve_rounding_c(const int32_t* src,
                             int src_stride,
                             uint8_t* dst,
                             int dst_stride,
                             int w,
                             int h,
                             int bits);
void av1_convolve_rounding_avx2(const int32_t* src,
                                int src_stride,
                                uint8_t* dst,
                                int dst_stride,
                                int w,
                                int h,
                                int bits);
RTCD_EXTERN void (*av1_convolve_rounding)(const int32_t* src,
                                          int src_stride,
                                          uint8_t* dst,
                                          int dst_stride,
                                          int w,
                                          int h,
                                          int bits);

void av1_convolve_vert_c(const uint8_t* src,
                         int src_stride,
                         uint8_t* dst,
                         int dst_stride,
                         int w,
                         int h,
                         const InterpFilterParams fp,
                         const int subpel_x_q4,
                         int x_step_q4,
                         ConvolveParams* conv_params);
void av1_convolve_vert_ssse3(const uint8_t* src,
                             int src_stride,
                             uint8_t* dst,
                             int dst_stride,
                             int w,
                             int h,
                             const InterpFilterParams fp,
                             const int subpel_x_q4,
                             int x_step_q4,
                             ConvolveParams* conv_params);
RTCD_EXTERN void (*av1_convolve_vert)(const uint8_t* src,
                                      int src_stride,
                                      uint8_t* dst,
                                      int dst_stride,
                                      int w,
                                      int h,
                                      const InterpFilterParams fp,
                                      const int subpel_x_q4,
                                      int x_step_q4,
                                      ConvolveParams* conv_params);

void av1_highbd_convolve8_c(const uint8_t* src,
                            ptrdiff_t src_stride,
                            uint8_t* dst,
                            ptrdiff_t dst_stride,
                            const int16_t* filter_x,
                            int x_step_q4,
                            const int16_t* filter_y,
                            int y_step_q4,
                            int w,
                            int h,
                            int bps);
#define av1_highbd_convolve8 av1_highbd_convolve8_c

void av1_highbd_convolve8_avg_c(const uint8_t* src,
                                ptrdiff_t src_stride,
                                uint8_t* dst,
                                ptrdiff_t dst_stride,
                                const int16_t* filter_x,
                                int x_step_q4,
                                const int16_t* filter_y,
                                int y_step_q4,
                                int w,
                                int h,
                                int bps);
#define av1_highbd_convolve8_avg av1_highbd_convolve8_avg_c

void av1_highbd_convolve8_avg_horiz_c(const uint8_t* src,
                                      ptrdiff_t src_stride,
                                      uint8_t* dst,
                                      ptrdiff_t dst_stride,
                                      const int16_t* filter_x,
                                      int x_step_q4,
                                      const int16_t* filter_y,
                                      int y_step_q4,
                                      int w,
                                      int h,
                                      int bps);
#define av1_highbd_convolve8_avg_horiz av1_highbd_convolve8_avg_horiz_c

void av1_highbd_convolve8_avg_vert_c(const uint8_t* src,
                                     ptrdiff_t src_stride,
                                     uint8_t* dst,
                                     ptrdiff_t dst_stride,
                                     const int16_t* filter_x,
                                     int x_step_q4,
                                     const int16_t* filter_y,
                                     int y_step_q4,
                                     int w,
                                     int h,
                                     int bps);
#define av1_highbd_convolve8_avg_vert av1_highbd_convolve8_avg_vert_c

void av1_highbd_convolve8_horiz_c(const uint8_t* src,
                                  ptrdiff_t src_stride,
                                  uint8_t* dst,
                                  ptrdiff_t dst_stride,
                                  const int16_t* filter_x,
                                  int x_step_q4,
                                  const int16_t* filter_y,
                                  int y_step_q4,
                                  int w,
                                  int h,
                                  int bps);
#define av1_highbd_convolve8_horiz av1_highbd_convolve8_horiz_c

void av1_highbd_convolve8_vert_c(const uint8_t* src,
                                 ptrdiff_t src_stride,
                                 uint8_t* dst,
                                 ptrdiff_t dst_stride,
                                 const int16_t* filter_x,
                                 int x_step_q4,
                                 const int16_t* filter_y,
                                 int y_step_q4,
                                 int w,
                                 int h,
                                 int bps);
#define av1_highbd_convolve8_vert av1_highbd_convolve8_vert_c

void av1_highbd_convolve_2d_c(const uint16_t* src,
                              int src_stride,
                              CONV_BUF_TYPE* dst,
                              int dst_stride,
                              int w,
                              int h,
                              InterpFilterParams* filter_params_x,
                              InterpFilterParams* filter_params_y,
                              const int subpel_x_q4,
                              const int subpel_y_q4,
                              ConvolveParams* conv_params,
                              int bd);
void av1_highbd_convolve_2d_ssse3(const uint16_t* src,
                                  int src_stride,
                                  CONV_BUF_TYPE* dst,
                                  int dst_stride,
                                  int w,
                                  int h,
                                  InterpFilterParams* filter_params_x,
                                  InterpFilterParams* filter_params_y,
                                  const int subpel_x_q4,
                                  const int subpel_y_q4,
                                  ConvolveParams* conv_params,
                                  int bd);
RTCD_EXTERN void (*av1_highbd_convolve_2d)(const uint16_t* src,
                                           int src_stride,
                                           CONV_BUF_TYPE* dst,
                                           int dst_stride,
                                           int w,
                                           int h,
                                           InterpFilterParams* filter_params_x,
                                           InterpFilterParams* filter_params_y,
                                           const int subpel_x_q4,
                                           const int subpel_y_q4,
                                           ConvolveParams* conv_params,
                                           int bd);

void av1_highbd_convolve_2d_scale_c(const uint16_t* src,
                                    int src_stride,
                                    CONV_BUF_TYPE* dst,
                                    int dst_stride,
                                    int w,
                                    int h,
                                    InterpFilterParams* filter_params_x,
                                    InterpFilterParams* filter_params_y,
                                    const int subpel_x_q4,
                                    const int x_step_qn,
                                    const int subpel_y_q4,
                                    const int y_step_qn,
                                    ConvolveParams* conv_params,
                                    int bd);
#define av1_highbd_convolve_2d_scale av1_highbd_convolve_2d_scale_c

void av1_highbd_convolve_avg_c(const uint8_t* src,
                               ptrdiff_t src_stride,
                               uint8_t* dst,
                               ptrdiff_t dst_stride,
                               const int16_t* filter_x,
                               int x_step_q4,
                               const int16_t* filter_y,
                               int y_step_q4,
                               int w,
                               int h,
                               int bps);
#define av1_highbd_convolve_avg av1_highbd_convolve_avg_c

void av1_highbd_convolve_copy_c(const uint8_t* src,
                                ptrdiff_t src_stride,
                                uint8_t* dst,
                                ptrdiff_t dst_stride,
                                const int16_t* filter_x,
                                int x_step_q4,
                                const int16_t* filter_y,
                                int y_step_q4,
                                int w,
                                int h,
                                int bps);
#define av1_highbd_convolve_copy av1_highbd_convolve_copy_c

void av1_highbd_convolve_horiz_c(const uint16_t* src,
                                 int src_stride,
                                 uint16_t* dst,
                                 int dst_stride,
                                 int w,
                                 int h,
                                 const InterpFilterParams fp,
                                 const int subpel_x_q4,
                                 int x_step_q4,
                                 int avg,
                                 int bd);
void av1_highbd_convolve_horiz_sse4_1(const uint16_t* src,
                                      int src_stride,
                                      uint16_t* dst,
                                      int dst_stride,
                                      int w,
                                      int h,
                                      const InterpFilterParams fp,
                                      const int subpel_x_q4,
                                      int x_step_q4,
                                      int avg,
                                      int bd);
RTCD_EXTERN void (*av1_highbd_convolve_horiz)(const uint16_t* src,
                                              int src_stride,
                                              uint16_t* dst,
                                              int dst_stride,
                                              int w,
                                              int h,
                                              const InterpFilterParams fp,
                                              const int subpel_x_q4,
                                              int x_step_q4,
                                              int avg,
                                              int bd);

void av1_highbd_convolve_init_c(void);
void av1_highbd_convolve_init_sse4_1(void);
RTCD_EXTERN void (*av1_highbd_convolve_init)(void);

void av1_highbd_convolve_rounding_c(const int32_t* src,
                                    int src_stride,
                                    uint8_t* dst,
                                    int dst_stride,
                                    int w,
                                    int h,
                                    int bits,
                                    int bd);
void av1_highbd_convolve_rounding_avx2(const int32_t* src,
                                       int src_stride,
                                       uint8_t* dst,
                                       int dst_stride,
                                       int w,
                                       int h,
                                       int bits,
                                       int bd);
RTCD_EXTERN void (*av1_highbd_convolve_rounding)(const int32_t* src,
                                                 int src_stride,
                                                 uint8_t* dst,
                                                 int dst_stride,
                                                 int w,
                                                 int h,
                                                 int bits,
                                                 int bd);

void av1_highbd_convolve_vert_c(const uint16_t* src,
                                int src_stride,
                                uint16_t* dst,
                                int dst_stride,
                                int w,
                                int h,
                                const InterpFilterParams fp,
                                const int subpel_x_q4,
                                int x_step_q4,
                                int avg,
                                int bd);
void av1_highbd_convolve_vert_sse4_1(const uint16_t* src,
                                     int src_stride,
                                     uint16_t* dst,
                                     int dst_stride,
                                     int w,
                                     int h,
                                     const InterpFilterParams fp,
                                     const int subpel_x_q4,
                                     int x_step_q4,
                                     int avg,
                                     int bd);
RTCD_EXTERN void (*av1_highbd_convolve_vert)(const uint16_t* src,
                                             int src_stride,
                                             uint16_t* dst,
                                             int dst_stride,
                                             int w,
                                             int h,
                                             const InterpFilterParams fp,
                                             const int subpel_x_q4,
                                             int x_step_q4,
                                             int avg,
                                             int bd);

void av1_highbd_iht16x16_256_add_c(const tran_low_t* input,
                                   uint8_t* output,
                                   int pitch,
                                   const struct txfm_param* param);
#define av1_highbd_iht16x16_256_add av1_highbd_iht16x16_256_add_c

void av1_highbd_iht16x32_512_add_c(const tran_low_t* input,
                                   uint8_t* dest,
                                   int dest_stride,
                                   const struct txfm_param* param);
#define av1_highbd_iht16x32_512_add av1_highbd_iht16x32_512_add_c

void av1_highbd_iht16x4_64_add_c(const tran_low_t* input,
                                 uint8_t* dest,
                                 int dest_stride,
                                 const struct txfm_param* param);
#define av1_highbd_iht16x4_64_add av1_highbd_iht16x4_64_add_c

void av1_highbd_iht16x8_128_add_c(const tran_low_t* input,
                                  uint8_t* dest,
                                  int dest_stride,
                                  const struct txfm_param* param);
#define av1_highbd_iht16x8_128_add av1_highbd_iht16x8_128_add_c

void av1_highbd_iht32x16_512_add_c(const tran_low_t* input,
                                   uint8_t* dest,
                                   int dest_stride,
                                   const struct txfm_param* param);
#define av1_highbd_iht32x16_512_add av1_highbd_iht32x16_512_add_c

void av1_highbd_iht32x8_256_add_c(const tran_low_t* input,
                                  uint8_t* dest,
                                  int dest_stride,
                                  const struct txfm_param* param);
#define av1_highbd_iht32x8_256_add av1_highbd_iht32x8_256_add_c

void av1_highbd_iht4x16_64_add_c(const tran_low_t* input,
                                 uint8_t* dest,
                                 int dest_stride,
                                 const struct txfm_param* param);
#define av1_highbd_iht4x16_64_add av1_highbd_iht4x16_64_add_c

void av1_highbd_iht4x4_16_add_c(const tran_low_t* input,
                                uint8_t* dest,
                                int dest_stride,
                                const struct txfm_param* param);
#define av1_highbd_iht4x4_16_add av1_highbd_iht4x4_16_add_c

void av1_highbd_iht4x8_32_add_c(const tran_low_t* input,
                                uint8_t* dest,
                                int dest_stride,
                                const struct txfm_param* param);
#define av1_highbd_iht4x8_32_add av1_highbd_iht4x8_32_add_c

void av1_highbd_iht8x16_128_add_c(const tran_low_t* input,
                                  uint8_t* dest,
                                  int dest_stride,
                                  const struct txfm_param* param);
#define av1_highbd_iht8x16_128_add av1_highbd_iht8x16_128_add_c

void av1_highbd_iht8x32_256_add_c(const tran_low_t* input,
                                  uint8_t* dest,
                                  int dest_stride,
                                  const struct txfm_param* param);
#define av1_highbd_iht8x32_256_add av1_highbd_iht8x32_256_add_c

void av1_highbd_iht8x4_32_add_c(const tran_low_t* input,
                                uint8_t* dest,
                                int dest_stride,
                                const struct txfm_param* param);
#define av1_highbd_iht8x4_32_add av1_highbd_iht8x4_32_add_c

void av1_highbd_iht8x8_64_add_c(const tran_low_t* input,
                                uint8_t* dest,
                                int dest_stride,
                                const struct txfm_param* param);
#define av1_highbd_iht8x8_64_add av1_highbd_iht8x8_64_add_c

void av1_highbd_warp_affine_c(const int32_t* mat,
                              const uint16_t* ref,
                              int width,
                              int height,
                              int stride,
                              uint16_t* pred,
                              int p_col,
                              int p_row,
                              int p_width,
                              int p_height,
                              int p_stride,
                              int subsampling_x,
                              int subsampling_y,
                              int bd,
                              ConvolveParams* conv_params,
                              int16_t alpha,
                              int16_t beta,
                              int16_t gamma,
                              int16_t delta);
void av1_highbd_warp_affine_ssse3(const int32_t* mat,
                                  const uint16_t* ref,
                                  int width,
                                  int height,
                                  int stride,
                                  uint16_t* pred,
                                  int p_col,
                                  int p_row,
                                  int p_width,
                                  int p_height,
                                  int p_stride,
                                  int subsampling_x,
                                  int subsampling_y,
                                  int bd,
                                  ConvolveParams* conv_params,
                                  int16_t alpha,
                                  int16_t beta,
                                  int16_t gamma,
                                  int16_t delta);
RTCD_EXTERN void (*av1_highbd_warp_affine)(const int32_t* mat,
                                           const uint16_t* ref,
                                           int width,
                                           int height,
                                           int stride,
                                           uint16_t* pred,
                                           int p_col,
                                           int p_row,
                                           int p_width,
                                           int p_height,
                                           int p_stride,
                                           int subsampling_x,
                                           int subsampling_y,
                                           int bd,
                                           ConvolveParams* conv_params,
                                           int16_t alpha,
                                           int16_t beta,
                                           int16_t gamma,
                                           int16_t delta);

void av1_iht16x16_256_add_c(const tran_low_t* input,
                            uint8_t* output,
                            int pitch,
                            const struct txfm_param* param);
void av1_iht16x16_256_add_sse2(const tran_low_t* input,
                               uint8_t* output,
                               int pitch,
                               const struct txfm_param* param);
void av1_iht16x16_256_add_avx2(const tran_low_t* input,
                               uint8_t* output,
                               int pitch,
                               const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht16x16_256_add)(const tran_low_t* input,
                                         uint8_t* output,
                                         int pitch,
                                         const struct txfm_param* param);

void av1_iht16x32_512_add_c(const tran_low_t* input,
                            uint8_t* dest,
                            int dest_stride,
                            const struct txfm_param* param);
void av1_iht16x32_512_add_sse2(const tran_low_t* input,
                               uint8_t* dest,
                               int dest_stride,
                               const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht16x32_512_add)(const tran_low_t* input,
                                         uint8_t* dest,
                                         int dest_stride,
                                         const struct txfm_param* param);

void av1_iht16x4_64_add_c(const tran_low_t* input,
                          uint8_t* dest,
                          int dest_stride,
                          const struct txfm_param* param);
#define av1_iht16x4_64_add av1_iht16x4_64_add_c

void av1_iht16x8_128_add_c(const tran_low_t* input,
                           uint8_t* dest,
                           int dest_stride,
                           const struct txfm_param* param);
void av1_iht16x8_128_add_sse2(const tran_low_t* input,
                              uint8_t* dest,
                              int dest_stride,
                              const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht16x8_128_add)(const tran_low_t* input,
                                        uint8_t* dest,
                                        int dest_stride,
                                        const struct txfm_param* param);

void av1_iht32x16_512_add_c(const tran_low_t* input,
                            uint8_t* dest,
                            int dest_stride,
                            const struct txfm_param* param);
void av1_iht32x16_512_add_sse2(const tran_low_t* input,
                               uint8_t* dest,
                               int dest_stride,
                               const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht32x16_512_add)(const tran_low_t* input,
                                         uint8_t* dest,
                                         int dest_stride,
                                         const struct txfm_param* param);

void av1_iht32x32_1024_add_c(const tran_low_t* input,
                             uint8_t* output,
                             int pitch,
                             const struct txfm_param* param);
#define av1_iht32x32_1024_add av1_iht32x32_1024_add_c

void av1_iht32x8_256_add_c(const tran_low_t* input,
                           uint8_t* dest,
                           int dest_stride,
                           const struct txfm_param* param);
#define av1_iht32x8_256_add av1_iht32x8_256_add_c

void av1_iht4x16_64_add_c(const tran_low_t* input,
                          uint8_t* dest,
                          int dest_stride,
                          const struct txfm_param* param);
#define av1_iht4x16_64_add av1_iht4x16_64_add_c

void av1_iht4x4_16_add_c(const tran_low_t* input,
                         uint8_t* dest,
                         int dest_stride,
                         const struct txfm_param* param);
void av1_iht4x4_16_add_sse2(const tran_low_t* input,
                            uint8_t* dest,
                            int dest_stride,
                            const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht4x4_16_add)(const tran_low_t* input,
                                      uint8_t* dest,
                                      int dest_stride,
                                      const struct txfm_param* param);

void av1_iht4x8_32_add_c(const tran_low_t* input,
                         uint8_t* dest,
                         int dest_stride,
                         const struct txfm_param* param);
void av1_iht4x8_32_add_sse2(const tran_low_t* input,
                            uint8_t* dest,
                            int dest_stride,
                            const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht4x8_32_add)(const tran_low_t* input,
                                      uint8_t* dest,
                                      int dest_stride,
                                      const struct txfm_param* param);

void av1_iht8x16_128_add_c(const tran_low_t* input,
                           uint8_t* dest,
                           int dest_stride,
                           const struct txfm_param* param);
void av1_iht8x16_128_add_sse2(const tran_low_t* input,
                              uint8_t* dest,
                              int dest_stride,
                              const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht8x16_128_add)(const tran_low_t* input,
                                        uint8_t* dest,
                                        int dest_stride,
                                        const struct txfm_param* param);

void av1_iht8x32_256_add_c(const tran_low_t* input,
                           uint8_t* dest,
                           int dest_stride,
                           const struct txfm_param* param);
#define av1_iht8x32_256_add av1_iht8x32_256_add_c

void av1_iht8x4_32_add_c(const tran_low_t* input,
                         uint8_t* dest,
                         int dest_stride,
                         const struct txfm_param* param);
void av1_iht8x4_32_add_sse2(const tran_low_t* input,
                            uint8_t* dest,
                            int dest_stride,
                            const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht8x4_32_add)(const tran_low_t* input,
                                      uint8_t* dest,
                                      int dest_stride,
                                      const struct txfm_param* param);

void av1_iht8x8_64_add_c(const tran_low_t* input,
                         uint8_t* dest,
                         int dest_stride,
                         const struct txfm_param* param);
void av1_iht8x8_64_add_sse2(const tran_low_t* input,
                            uint8_t* dest,
                            int dest_stride,
                            const struct txfm_param* param);
RTCD_EXTERN void (*av1_iht8x8_64_add)(const tran_low_t* input,
                                      uint8_t* dest,
                                      int dest_stride,
                                      const struct txfm_param* param);

void av1_inv_txfm2d_add_16x16_c(const int32_t* input,
                                uint16_t* output,
                                int stride,
                                int tx_type,
                                int bd);
void av1_inv_txfm2d_add_16x16_sse4_1(const int32_t* input,
                                     uint16_t* output,
                                     int stride,
                                     int tx_type,
                                     int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_16x16)(const int32_t* input,
                                             uint16_t* output,
                                             int stride,
                                             int tx_type,
                                             int bd);

void av1_inv_txfm2d_add_16x32_c(const int32_t* input,
                                uint16_t* output,
                                int stride,
                                int tx_type,
                                int bd);
#define av1_inv_txfm2d_add_16x32 av1_inv_txfm2d_add_16x32_c

void av1_inv_txfm2d_add_16x8_c(const int32_t* input,
                               uint16_t* output,
                               int stride,
                               int tx_type,
                               int bd);
#define av1_inv_txfm2d_add_16x8 av1_inv_txfm2d_add_16x8_c

void av1_inv_txfm2d_add_32x16_c(const int32_t* input,
                                uint16_t* output,
                                int stride,
                                int tx_type,
                                int bd);
#define av1_inv_txfm2d_add_32x16 av1_inv_txfm2d_add_32x16_c

void av1_inv_txfm2d_add_32x32_c(const int32_t* input,
                                uint16_t* output,
                                int stride,
                                int tx_type,
                                int bd);
void av1_inv_txfm2d_add_32x32_avx2(const int32_t* input,
                                   uint16_t* output,
                                   int stride,
                                   int tx_type,
                                   int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_32x32)(const int32_t* input,
                                             uint16_t* output,
                                             int stride,
                                             int tx_type,
                                             int bd);

void av1_inv_txfm2d_add_4x4_c(const int32_t* input,
                              uint16_t* output,
                              int stride,
                              int tx_type,
                              int bd);
void av1_inv_txfm2d_add_4x4_sse4_1(const int32_t* input,
                                   uint16_t* output,
                                   int stride,
                                   int tx_type,
                                   int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_4x4)(const int32_t* input,
                                           uint16_t* output,
                                           int stride,
                                           int tx_type,
                                           int bd);

void av1_inv_txfm2d_add_4x8_c(const int32_t* input,
                              uint16_t* output,
                              int stride,
                              int tx_type,
                              int bd);
#define av1_inv_txfm2d_add_4x8 av1_inv_txfm2d_add_4x8_c

void av1_inv_txfm2d_add_64x64_c(const int32_t* input,
                                uint16_t* output,
                                int stride,
                                int tx_type,
                                int bd);
#define av1_inv_txfm2d_add_64x64 av1_inv_txfm2d_add_64x64_c

void av1_inv_txfm2d_add_8x16_c(const int32_t* input,
                               uint16_t* output,
                               int stride,
                               int tx_type,
                               int bd);
#define av1_inv_txfm2d_add_8x16 av1_inv_txfm2d_add_8x16_c

void av1_inv_txfm2d_add_8x4_c(const int32_t* input,
                              uint16_t* output,
                              int stride,
                              int tx_type,
                              int bd);
#define av1_inv_txfm2d_add_8x4 av1_inv_txfm2d_add_8x4_c

void av1_inv_txfm2d_add_8x8_c(const int32_t* input,
                              uint16_t* output,
                              int stride,
                              int tx_type,
                              int bd);
void av1_inv_txfm2d_add_8x8_sse4_1(const int32_t* input,
                                   uint16_t* output,
                                   int stride,
                                   int tx_type,
                                   int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_8x8)(const int32_t* input,
                                           uint16_t* output,
                                           int stride,
                                           int tx_type,
                                           int bd);

void av1_lowbd_convolve_init_c(void);
void av1_lowbd_convolve_init_ssse3(void);
RTCD_EXTERN void (*av1_lowbd_convolve_init)(void);

void av1_warp_affine_c(const int32_t* mat,
                       const uint8_t* ref,
                       int width,
                       int height,
                       int stride,
                       uint8_t* pred,
                       int p_col,
                       int p_row,
                       int p_width,
                       int p_height,
                       int p_stride,
                       int subsampling_x,
                       int subsampling_y,
                       ConvolveParams* conv_params,
                       int16_t alpha,
                       int16_t beta,
                       int16_t gamma,
                       int16_t delta);
void av1_warp_affine_sse2(const int32_t* mat,
                          const uint8_t* ref,
                          int width,
                          int height,
                          int stride,
                          uint8_t* pred,
                          int p_col,
                          int p_row,
                          int p_width,
                          int p_height,
                          int p_stride,
                          int subsampling_x,
                          int subsampling_y,
                          ConvolveParams* conv_params,
                          int16_t alpha,
                          int16_t beta,
                          int16_t gamma,
                          int16_t delta);
void av1_warp_affine_ssse3(const int32_t* mat,
                           const uint8_t* ref,
                           int width,
                           int height,
                           int stride,
                           uint8_t* pred,
                           int p_col,
                           int p_row,
                           int p_width,
                           int p_height,
                           int p_stride,
                           int subsampling_x,
                           int subsampling_y,
                           ConvolveParams* conv_params,
                           int16_t alpha,
                           int16_t beta,
                           int16_t gamma,
                           int16_t delta);
RTCD_EXTERN void (*av1_warp_affine)(const int32_t* mat,
                                    const uint8_t* ref,
                                    int width,
                                    int height,
                                    int stride,
                                    uint8_t* pred,
                                    int p_col,
                                    int p_row,
                                    int p_width,
                                    int p_height,
                                    int p_stride,
                                    int subsampling_x,
                                    int subsampling_y,
                                    ConvolveParams* conv_params,
                                    int16_t alpha,
                                    int16_t beta,
                                    int16_t gamma,
                                    int16_t delta);

void cdef_direction_4x4_c(uint16_t* y,
                          int ystride,
                          const uint16_t* in,
                          int threshold,
                          int dir,
                          int damping);
void cdef_direction_4x4_sse2(uint16_t* y,
                             int ystride,
                             const uint16_t* in,
                             int threshold,
                             int dir,
                             int damping);
void cdef_direction_4x4_ssse3(uint16_t* y,
                              int ystride,
                              const uint16_t* in,
                              int threshold,
                              int dir,
                              int damping);
void cdef_direction_4x4_sse4_1(uint16_t* y,
                               int ystride,
                               const uint16_t* in,
                               int threshold,
                               int dir,
                               int damping);
RTCD_EXTERN void (*cdef_direction_4x4)(uint16_t* y,
                                       int ystride,
                                       const uint16_t* in,
                                       int threshold,
                                       int dir,
                                       int damping);

void cdef_direction_8x8_c(uint16_t* y,
                          int ystride,
                          const uint16_t* in,
                          int threshold,
                          int dir,
                          int damping);
void cdef_direction_8x8_sse2(uint16_t* y,
                             int ystride,
                             const uint16_t* in,
                             int threshold,
                             int dir,
                             int damping);
void cdef_direction_8x8_ssse3(uint16_t* y,
                              int ystride,
                              const uint16_t* in,
                              int threshold,
                              int dir,
                              int damping);
void cdef_direction_8x8_sse4_1(uint16_t* y,
                               int ystride,
                               const uint16_t* in,
                               int threshold,
                               int dir,
                               int damping);
RTCD_EXTERN void (*cdef_direction_8x8)(uint16_t* y,
                                       int ystride,
                                       const uint16_t* in,
                                       int threshold,
                                       int dir,
                                       int damping);

int cdef_find_dir_c(const uint16_t* img,
                    int stride,
                    int32_t* var,
                    int coeff_shift);
int cdef_find_dir_sse2(const uint16_t* img,
                       int stride,
                       int32_t* var,
                       int coeff_shift);
int cdef_find_dir_ssse3(const uint16_t* img,
                        int stride,
                        int32_t* var,
                        int coeff_shift);
int cdef_find_dir_sse4_1(const uint16_t* img,
                         int stride,
                         int32_t* var,
                         int coeff_shift);
RTCD_EXTERN int (*cdef_find_dir)(const uint16_t* img,
                                 int stride,
                                 int32_t* var,
                                 int coeff_shift);

void copy_4x4_16bit_to_16bit_c(uint16_t* dst,
                               int dstride,
                               const uint16_t* src,
                               int sstride);
void copy_4x4_16bit_to_16bit_sse2(uint16_t* dst,
                                  int dstride,
                                  const uint16_t* src,
                                  int sstride);
void copy_4x4_16bit_to_16bit_ssse3(uint16_t* dst,
                                   int dstride,
                                   const uint16_t* src,
                                   int sstride);
void copy_4x4_16bit_to_16bit_sse4_1(uint16_t* dst,
                                    int dstride,
                                    const uint16_t* src,
                                    int sstride);
RTCD_EXTERN void (*copy_4x4_16bit_to_16bit)(uint16_t* dst,
                                            int dstride,
                                            const uint16_t* src,
                                            int sstride);

void copy_4x4_16bit_to_8bit_c(uint8_t* dst,
                              int dstride,
                              const uint16_t* src,
                              int sstride);
void copy_4x4_16bit_to_8bit_sse2(uint8_t* dst,
                                 int dstride,
                                 const uint16_t* src,
                                 int sstride);
void copy_4x4_16bit_to_8bit_ssse3(uint8_t* dst,
                                  int dstride,
                                  const uint16_t* src,
                                  int sstride);
void copy_4x4_16bit_to_8bit_sse4_1(uint8_t* dst,
                                   int dstride,
                                   const uint16_t* src,
                                   int sstride);
RTCD_EXTERN void (*copy_4x4_16bit_to_8bit)(uint8_t* dst,
                                           int dstride,
                                           const uint16_t* src,
                                           int sstride);

void copy_8x8_16bit_to_16bit_c(uint16_t* dst,
                               int dstride,
                               const uint16_t* src,
                               int sstride);
void copy_8x8_16bit_to_16bit_sse2(uint16_t* dst,
                                  int dstride,
                                  const uint16_t* src,
                                  int sstride);
void copy_8x8_16bit_to_16bit_ssse3(uint16_t* dst,
                                   int dstride,
                                   const uint16_t* src,
                                   int sstride);
void copy_8x8_16bit_to_16bit_sse4_1(uint16_t* dst,
                                    int dstride,
                                    const uint16_t* src,
                                    int sstride);
RTCD_EXTERN void (*copy_8x8_16bit_to_16bit)(uint16_t* dst,
                                            int dstride,
                                            const uint16_t* src,
                                            int sstride);

void copy_8x8_16bit_to_8bit_c(uint8_t* dst,
                              int dstride,
                              const uint16_t* src,
                              int sstride);
void copy_8x8_16bit_to_8bit_sse2(uint8_t* dst,
                                 int dstride,
                                 const uint16_t* src,
                                 int sstride);
void copy_8x8_16bit_to_8bit_ssse3(uint8_t* dst,
                                  int dstride,
                                  const uint16_t* src,
                                  int sstride);
void copy_8x8_16bit_to_8bit_sse4_1(uint8_t* dst,
                                   int dstride,
                                   const uint16_t* src,
                                   int sstride);
RTCD_EXTERN void (*copy_8x8_16bit_to_8bit)(uint8_t* dst,
                                           int dstride,
                                           const uint16_t* src,
                                           int sstride);

void copy_rect8_16bit_to_16bit_c(uint16_t* dst,
                                 int dstride,
                                 const uint16_t* src,
                                 int sstride,
                                 int v,
                                 int h);
void copy_rect8_16bit_to_16bit_sse2(uint16_t* dst,
                                    int dstride,
                                    const uint16_t* src,
                                    int sstride,
                                    int v,
                                    int h);
void copy_rect8_16bit_to_16bit_ssse3(uint16_t* dst,
                                     int dstride,
                                     const uint16_t* src,
                                     int sstride,
                                     int v,
                                     int h);
void copy_rect8_16bit_to_16bit_sse4_1(uint16_t* dst,
                                      int dstride,
                                      const uint16_t* src,
                                      int sstride,
                                      int v,
                                      int h);
RTCD_EXTERN void (*copy_rect8_16bit_to_16bit)(uint16_t* dst,
                                              int dstride,
                                              const uint16_t* src,
                                              int sstride,
                                              int v,
                                              int h);

void copy_rect8_8bit_to_16bit_c(uint16_t* dst,
                                int dstride,
                                const uint8_t* src,
                                int sstride,
                                int v,
                                int h);
void copy_rect8_8bit_to_16bit_sse2(uint16_t* dst,
                                   int dstride,
                                   const uint8_t* src,
                                   int sstride,
                                   int v,
                                   int h);
void copy_rect8_8bit_to_16bit_ssse3(uint16_t* dst,
                                    int dstride,
                                    const uint8_t* src,
                                    int sstride,
                                    int v,
                                    int h);
void copy_rect8_8bit_to_16bit_sse4_1(uint16_t* dst,
                                     int dstride,
                                     const uint8_t* src,
                                     int sstride,
                                     int v,
                                     int h);
RTCD_EXTERN void (*copy_rect8_8bit_to_16bit)(uint16_t* dst,
                                             int dstride,
                                             const uint8_t* src,
                                             int sstride,
                                             int v,
                                             int h);

void av1_rtcd(void);

#ifdef RTCD_C
#include "aom_ports/x86.h"
static void setup_rtcd_internal(void) {
  int flags = x86_simd_caps();

  (void)flags;

  aom_clpf_block = aom_clpf_block_c;
  if (flags & HAS_SSE2)
    aom_clpf_block = aom_clpf_block_sse2;
  if (flags & HAS_SSSE3)
    aom_clpf_block = aom_clpf_block_ssse3;
  if (flags & HAS_SSE4_1)
    aom_clpf_block = aom_clpf_block_sse4_1;
  aom_clpf_block_hbd = aom_clpf_block_hbd_c;
  if (flags & HAS_SSE2)
    aom_clpf_block_hbd = aom_clpf_block_hbd_sse2;
  if (flags & HAS_SSSE3)
    aom_clpf_block_hbd = aom_clpf_block_hbd_ssse3;
  if (flags & HAS_SSE4_1)
    aom_clpf_block_hbd = aom_clpf_block_hbd_sse4_1;
  aom_clpf_hblock = aom_clpf_hblock_c;
  if (flags & HAS_SSE2)
    aom_clpf_hblock = aom_clpf_hblock_sse2;
  if (flags & HAS_SSSE3)
    aom_clpf_hblock = aom_clpf_hblock_ssse3;
  if (flags & HAS_SSE4_1)
    aom_clpf_hblock = aom_clpf_hblock_sse4_1;
  aom_clpf_hblock_hbd = aom_clpf_hblock_hbd_c;
  if (flags & HAS_SSE2)
    aom_clpf_hblock_hbd = aom_clpf_hblock_hbd_sse2;
  if (flags & HAS_SSSE3)
    aom_clpf_hblock_hbd = aom_clpf_hblock_hbd_ssse3;
  if (flags & HAS_SSE4_1)
    aom_clpf_hblock_hbd = aom_clpf_hblock_hbd_sse4_1;
  av1_convolve_2d = av1_convolve_2d_c;
  if (flags & HAS_SSE2)
    av1_convolve_2d = av1_convolve_2d_sse2;
  av1_convolve_horiz = av1_convolve_horiz_c;
  if (flags & HAS_SSSE3)
    av1_convolve_horiz = av1_convolve_horiz_ssse3;
  av1_convolve_rounding = av1_convolve_rounding_c;
  if (flags & HAS_AVX2)
    av1_convolve_rounding = av1_convolve_rounding_avx2;
  av1_convolve_vert = av1_convolve_vert_c;
  if (flags & HAS_SSSE3)
    av1_convolve_vert = av1_convolve_vert_ssse3;
  av1_highbd_convolve_2d = av1_highbd_convolve_2d_c;
  if (flags & HAS_SSSE3)
    av1_highbd_convolve_2d = av1_highbd_convolve_2d_ssse3;
  av1_highbd_convolve_horiz = av1_highbd_convolve_horiz_c;
  if (flags & HAS_SSE4_1)
    av1_highbd_convolve_horiz = av1_highbd_convolve_horiz_sse4_1;
  av1_highbd_convolve_init = av1_highbd_convolve_init_c;
  if (flags & HAS_SSE4_1)
    av1_highbd_convolve_init = av1_highbd_convolve_init_sse4_1;
  av1_highbd_convolve_rounding = av1_highbd_convolve_rounding_c;
  if (flags & HAS_AVX2)
    av1_highbd_convolve_rounding = av1_highbd_convolve_rounding_avx2;
  av1_highbd_convolve_vert = av1_highbd_convolve_vert_c;
  if (flags & HAS_SSE4_1)
    av1_highbd_convolve_vert = av1_highbd_convolve_vert_sse4_1;
  av1_highbd_warp_affine = av1_highbd_warp_affine_c;
  if (flags & HAS_SSSE3)
    av1_highbd_warp_affine = av1_highbd_warp_affine_ssse3;
  av1_iht16x16_256_add = av1_iht16x16_256_add_c;
  if (flags & HAS_SSE2)
    av1_iht16x16_256_add = av1_iht16x16_256_add_sse2;
  if (flags & HAS_AVX2)
    av1_iht16x16_256_add = av1_iht16x16_256_add_avx2;
  av1_iht16x32_512_add = av1_iht16x32_512_add_c;
  if (flags & HAS_SSE2)
    av1_iht16x32_512_add = av1_iht16x32_512_add_sse2;
  av1_iht16x8_128_add = av1_iht16x8_128_add_c;
  if (flags & HAS_SSE2)
    av1_iht16x8_128_add = av1_iht16x8_128_add_sse2;
  av1_iht32x16_512_add = av1_iht32x16_512_add_c;
  if (flags & HAS_SSE2)
    av1_iht32x16_512_add = av1_iht32x16_512_add_sse2;
  av1_iht4x4_16_add = av1_iht4x4_16_add_c;
  if (flags & HAS_SSE2)
    av1_iht4x4_16_add = av1_iht4x4_16_add_sse2;
  av1_iht4x8_32_add = av1_iht4x8_32_add_c;
  if (flags & HAS_SSE2)
    av1_iht4x8_32_add = av1_iht4x8_32_add_sse2;
  av1_iht8x16_128_add = av1_iht8x16_128_add_c;
  if (flags & HAS_SSE2)
    av1_iht8x16_128_add = av1_iht8x16_128_add_sse2;
  av1_iht8x4_32_add = av1_iht8x4_32_add_c;
  if (flags & HAS_SSE2)
    av1_iht8x4_32_add = av1_iht8x4_32_add_sse2;
  av1_iht8x8_64_add = av1_iht8x8_64_add_c;
  if (flags & HAS_SSE2)
    av1_iht8x8_64_add = av1_iht8x8_64_add_sse2;
  av1_inv_txfm2d_add_16x16 = av1_inv_txfm2d_add_16x16_c;
  if (flags & HAS_SSE4_1)
    av1_inv_txfm2d_add_16x16 = av1_inv_txfm2d_add_16x16_sse4_1;
  av1_inv_txfm2d_add_32x32 = av1_inv_txfm2d_add_32x32_c;
  if (flags & HAS_AVX2)
    av1_inv_txfm2d_add_32x32 = av1_inv_txfm2d_add_32x32_avx2;
  av1_inv_txfm2d_add_4x4 = av1_inv_txfm2d_add_4x4_c;
  if (flags & HAS_SSE4_1)
    av1_inv_txfm2d_add_4x4 = av1_inv_txfm2d_add_4x4_sse4_1;
  av1_inv_txfm2d_add_8x8 = av1_inv_txfm2d_add_8x8_c;
  if (flags & HAS_SSE4_1)
    av1_inv_txfm2d_add_8x8 = av1_inv_txfm2d_add_8x8_sse4_1;
  av1_lowbd_convolve_init = av1_lowbd_convolve_init_c;
  if (flags & HAS_SSSE3)
    av1_lowbd_convolve_init = av1_lowbd_convolve_init_ssse3;
  av1_warp_affine = av1_warp_affine_c;
  if (flags & HAS_SSE2)
    av1_warp_affine = av1_warp_affine_sse2;
  if (flags & HAS_SSSE3)
    av1_warp_affine = av1_warp_affine_ssse3;
  cdef_direction_4x4 = cdef_direction_4x4_c;
  if (flags & HAS_SSE2)
    cdef_direction_4x4 = cdef_direction_4x4_sse2;
  if (flags & HAS_SSSE3)
    cdef_direction_4x4 = cdef_direction_4x4_ssse3;
  if (flags & HAS_SSE4_1)
    cdef_direction_4x4 = cdef_direction_4x4_sse4_1;
  cdef_direction_8x8 = cdef_direction_8x8_c;
  if (flags & HAS_SSE2)
    cdef_direction_8x8 = cdef_direction_8x8_sse2;
  if (flags & HAS_SSSE3)
    cdef_direction_8x8 = cdef_direction_8x8_ssse3;
  if (flags & HAS_SSE4_1)
    cdef_direction_8x8 = cdef_direction_8x8_sse4_1;
  cdef_find_dir = cdef_find_dir_c;
  if (flags & HAS_SSE2)
    cdef_find_dir = cdef_find_dir_sse2;
  if (flags & HAS_SSSE3)
    cdef_find_dir = cdef_find_dir_ssse3;
  if (flags & HAS_SSE4_1)
    cdef_find_dir = cdef_find_dir_sse4_1;
  copy_4x4_16bit_to_16bit = copy_4x4_16bit_to_16bit_c;
  if (flags & HAS_SSE2)
    copy_4x4_16bit_to_16bit = copy_4x4_16bit_to_16bit_sse2;
  if (flags & HAS_SSSE3)
    copy_4x4_16bit_to_16bit = copy_4x4_16bit_to_16bit_ssse3;
  if (flags & HAS_SSE4_1)
    copy_4x4_16bit_to_16bit = copy_4x4_16bit_to_16bit_sse4_1;
  copy_4x4_16bit_to_8bit = copy_4x4_16bit_to_8bit_c;
  if (flags & HAS_SSE2)
    copy_4x4_16bit_to_8bit = copy_4x4_16bit_to_8bit_sse2;
  if (flags & HAS_SSSE3)
    copy_4x4_16bit_to_8bit = copy_4x4_16bit_to_8bit_ssse3;
  if (flags & HAS_SSE4_1)
    copy_4x4_16bit_to_8bit = copy_4x4_16bit_to_8bit_sse4_1;
  copy_8x8_16bit_to_16bit = copy_8x8_16bit_to_16bit_c;
  if (flags & HAS_SSE2)
    copy_8x8_16bit_to_16bit = copy_8x8_16bit_to_16bit_sse2;
  if (flags & HAS_SSSE3)
    copy_8x8_16bit_to_16bit = copy_8x8_16bit_to_16bit_ssse3;
  if (flags & HAS_SSE4_1)
    copy_8x8_16bit_to_16bit = copy_8x8_16bit_to_16bit_sse4_1;
  copy_8x8_16bit_to_8bit = copy_8x8_16bit_to_8bit_c;
  if (flags & HAS_SSE2)
    copy_8x8_16bit_to_8bit = copy_8x8_16bit_to_8bit_sse2;
  if (flags & HAS_SSSE3)
    copy_8x8_16bit_to_8bit = copy_8x8_16bit_to_8bit_ssse3;
  if (flags & HAS_SSE4_1)
    copy_8x8_16bit_to_8bit = copy_8x8_16bit_to_8bit_sse4_1;
  copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_c;
  if (flags & HAS_SSE2)
    copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_sse2;
  if (flags & HAS_SSSE3)
    copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_ssse3;
  if (flags & HAS_SSE4_1)
    copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_sse4_1;
  copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_c;
  if (flags & HAS_SSE2)
    copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_sse2;
  if (flags & HAS_SSSE3)
    copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_ssse3;
  if (flags & HAS_SSE4_1)
    copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_sse4_1;
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
