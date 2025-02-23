/***************************************************************
 * Name:      risc-v_opcodes.h
 * Purpose:   声明risc-v_opcodes接口
 * Author:    HYH (hyhsystem.cn)
 * Created:   2025-02-17
 * Copyright: HYH (hyhsystem.cn)
 * License:   MIT
 **************************************************************/
#ifndef __HS_RISC_V_OPCODES_H__
#define __HS_RISC_V_OPCODES_H__
#include "stdint.h"
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

struct hs_risc_v_opcodes_insn;
typedef struct hs_risc_v_opcodes_insn hs_risc_v_opcodes_insn_t;

struct  hs_risc_v_opcodes_insn
{
    const char *name;   /**< 指令名称 */
    uint32_t    match;  /**< 指令匹配值 */
    uint32_t    mask;   /**< 指令匹配掩码 */
};


/** \brief 声明要使用的INSN
 *
 *
 */
#ifdef __cplusplus
#define HS_RISC_V_OPCODES_INSN_DECLARE(NAME) \
extern "C" const hs_risc_v_opcodes_insn_t hs_risc_v_opcodes_insn_##NAME
#else
#define HS_RISC_V_OPCODES_INSN_DECLARE(NAME) \
extern const hs_risc_v_opcodes_insn_t hs_risc_v_opcodes_insn_##NAME
#endif


/** \brief 获取INSN的名称
 *
 *
 */
#define HS_RISC_V_OPCODES_INSN_NAME(NAME) (hs_risc_v_opcodes_insn_##NAME)


/*
 *  RV32I
 */
HS_RISC_V_OPCODES_INSN_DECLARE(lui);
HS_RISC_V_OPCODES_INSN_DECLARE(auipc);
HS_RISC_V_OPCODES_INSN_DECLARE(jal);
HS_RISC_V_OPCODES_INSN_DECLARE(jalr);
HS_RISC_V_OPCODES_INSN_DECLARE(beq);
HS_RISC_V_OPCODES_INSN_DECLARE(bne);
HS_RISC_V_OPCODES_INSN_DECLARE(blt);
HS_RISC_V_OPCODES_INSN_DECLARE(bge);
HS_RISC_V_OPCODES_INSN_DECLARE(bltu);
HS_RISC_V_OPCODES_INSN_DECLARE(bgeu);
HS_RISC_V_OPCODES_INSN_DECLARE(lb);
HS_RISC_V_OPCODES_INSN_DECLARE(lh);
HS_RISC_V_OPCODES_INSN_DECLARE(lw);
HS_RISC_V_OPCODES_INSN_DECLARE(lbu);
HS_RISC_V_OPCODES_INSN_DECLARE(lhu);
HS_RISC_V_OPCODES_INSN_DECLARE(sb);
HS_RISC_V_OPCODES_INSN_DECLARE(sh);
HS_RISC_V_OPCODES_INSN_DECLARE(sw);
HS_RISC_V_OPCODES_INSN_DECLARE(addi);
HS_RISC_V_OPCODES_INSN_DECLARE(slti);
HS_RISC_V_OPCODES_INSN_DECLARE(xori);
HS_RISC_V_OPCODES_INSN_DECLARE(ori);
HS_RISC_V_OPCODES_INSN_DECLARE(andi);
HS_RISC_V_OPCODES_INSN_DECLARE(add);
HS_RISC_V_OPCODES_INSN_DECLARE(sub);
HS_RISC_V_OPCODES_INSN_DECLARE(sll);
HS_RISC_V_OPCODES_INSN_DECLARE(slt);
HS_RISC_V_OPCODES_INSN_DECLARE(sltu);
HS_RISC_V_OPCODES_INSN_DECLARE(xor);
HS_RISC_V_OPCODES_INSN_DECLARE(srl);
HS_RISC_V_OPCODES_INSN_DECLARE(sra);
HS_RISC_V_OPCODES_INSN_DECLARE(or);
HS_RISC_V_OPCODES_INSN_DECLARE(and);
HS_RISC_V_OPCODES_INSN_DECLARE(fence);
HS_RISC_V_OPCODES_INSN_DECLARE(ecall);
HS_RISC_V_OPCODES_INSN_DECLARE(ebreak);
HS_RISC_V_OPCODES_INSN_DECLARE(slli);
HS_RISC_V_OPCODES_INSN_DECLARE(srli);
HS_RISC_V_OPCODES_INSN_DECLARE(srai);
HS_RISC_V_OPCODES_INSN_DECLARE(pause);

/*
 *  RV64I（较RV32I新增）
 */
HS_RISC_V_OPCODES_INSN_DECLARE(lwu);
HS_RISC_V_OPCODES_INSN_DECLARE(ld);
HS_RISC_V_OPCODES_INSN_DECLARE(sd);
HS_RISC_V_OPCODES_INSN_DECLARE(slli);
HS_RISC_V_OPCODES_INSN_DECLARE(srli);
HS_RISC_V_OPCODES_INSN_DECLARE(srai);
HS_RISC_V_OPCODES_INSN_DECLARE(addw);
HS_RISC_V_OPCODES_INSN_DECLARE(subw);
HS_RISC_V_OPCODES_INSN_DECLARE(sllw);
HS_RISC_V_OPCODES_INSN_DECLARE(srlw);
HS_RISC_V_OPCODES_INSN_DECLARE(sraw);

/*
 *  RV32/RV64 Zifencei
 */
HS_RISC_V_OPCODES_INSN_DECLARE(fence_i);


/*
 *  RV32/RV64 Zicsr
 */
HS_RISC_V_OPCODES_INSN_DECLARE(csrrw);
HS_RISC_V_OPCODES_INSN_DECLARE(csrrs);
HS_RISC_V_OPCODES_INSN_DECLARE(csrrc);
HS_RISC_V_OPCODES_INSN_DECLARE(csrrwi);
HS_RISC_V_OPCODES_INSN_DECLARE(csrrsi);
HS_RISC_V_OPCODES_INSN_DECLARE(csrrci);

/*
 *  RV32M
 */
HS_RISC_V_OPCODES_INSN_DECLARE(mul);
HS_RISC_V_OPCODES_INSN_DECLARE(mulh);
HS_RISC_V_OPCODES_INSN_DECLARE(mulhsu);
HS_RISC_V_OPCODES_INSN_DECLARE(mulhu);
HS_RISC_V_OPCODES_INSN_DECLARE(div);
HS_RISC_V_OPCODES_INSN_DECLARE(divu);
HS_RISC_V_OPCODES_INSN_DECLARE(rem);
HS_RISC_V_OPCODES_INSN_DECLARE(remu);

/*
 *  RV64M (较RV32M新增)
 */
HS_RISC_V_OPCODES_INSN_DECLARE(mulw);
HS_RISC_V_OPCODES_INSN_DECLARE(divw);
HS_RISC_V_OPCODES_INSN_DECLARE(divuw);
HS_RISC_V_OPCODES_INSN_DECLARE(remw);
HS_RISC_V_OPCODES_INSN_DECLARE(remuw);

/*
 *  RV32A
 */
HS_RISC_V_OPCODES_INSN_DECLARE(lr_w);
HS_RISC_V_OPCODES_INSN_DECLARE(sc_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amoswap_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amoadd_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amoxor_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amoand_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amoor_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amomin_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amomax_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amominu_w);
HS_RISC_V_OPCODES_INSN_DECLARE(amomaxu_w);


/*
 * RV64A (较RV32A新增)
 */
HS_RISC_V_OPCODES_INSN_DECLARE(lr_d);
HS_RISC_V_OPCODES_INSN_DECLARE(sc_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amoswap_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amoadd_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amoxor_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amoand_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amoor_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amomin_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amomax_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amominu_d);
HS_RISC_V_OPCODES_INSN_DECLARE(amomaxu_d);

/*
 *  RV32F
 */
HS_RISC_V_OPCODES_INSN_DECLARE(flw);
HS_RISC_V_OPCODES_INSN_DECLARE(fsw);
HS_RISC_V_OPCODES_INSN_DECLARE(fmadd_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fmsub_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fnmsub_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fnmadd_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fadd_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fsub_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fmul_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fdiv_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fsqrt_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fsgnj_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fsgnjn_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fsgnjx_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fmin_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fmax_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_w_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_wu_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fmv_x_w);
HS_RISC_V_OPCODES_INSN_DECLARE(feq_s);
HS_RISC_V_OPCODES_INSN_DECLARE(flt_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fle_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fclass_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_s_w);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_s_wu);
HS_RISC_V_OPCODES_INSN_DECLARE(fmv_w_x);
HS_RISC_V_OPCODES_INSN_DECLARE(frflags);
HS_RISC_V_OPCODES_INSN_DECLARE(fsflags);
HS_RISC_V_OPCODES_INSN_DECLARE(fsflagsi);
HS_RISC_V_OPCODES_INSN_DECLARE(frrm);
HS_RISC_V_OPCODES_INSN_DECLARE(fsrm);
HS_RISC_V_OPCODES_INSN_DECLARE(fsrmi);
HS_RISC_V_OPCODES_INSN_DECLARE(fscsr);
HS_RISC_V_OPCODES_INSN_DECLARE(frcsr);

/*
 *  RV64F (较RV32F新增)
 */
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_l_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_lu_s);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_s_l);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_s_lu);

/*
 *  RV32D
 */
HS_RISC_V_OPCODES_INSN_DECLARE(fld);
HS_RISC_V_OPCODES_INSN_DECLARE(fsd);
HS_RISC_V_OPCODES_INSN_DECLARE(fmadd_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fmsub_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fnmsub_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fnmadd_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fadd_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fsub_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fmul_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fdiv_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fsqrt_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fsgnj_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fsgnjn_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fsgnjx_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fmin_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fmax_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_s_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_d_s);
HS_RISC_V_OPCODES_INSN_DECLARE(feq_d);
HS_RISC_V_OPCODES_INSN_DECLARE(flt_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fle_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fclass_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_w_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_wu_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_d_w);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_d_wu);

/*
 *  RV64D (较RV32D新增)
 */
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_l_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_lu_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fmv_x_d);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_d_l);
HS_RISC_V_OPCODES_INSN_DECLARE(fcvt_d_lu);
HS_RISC_V_OPCODES_INSN_DECLARE(fmv_d_x);

/*
 *  RVC 指令集，RVC指令集与其它指令集不同，可被加在基本指令集上，可替换原有指令用于压缩指令。
 *  RVC中的指令会根据具体的基本指令集不同而不同。
 *  RVC中的指令根据最低两位的值可分为0、1、2三个象限，当最低两位为3时表示32位及更高位数的指令
 */
//象限0
HS_RISC_V_OPCODES_INSN_DECLARE(c_addi4spn);
HS_RISC_V_OPCODES_INSN_DECLARE(c_fld);
HS_RISC_V_OPCODES_INSN_DECLARE(c_lq);
HS_RISC_V_OPCODES_INSN_DECLARE(c_lw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_flw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_ld);
HS_RISC_V_OPCODES_INSN_DECLARE(c_fsd);
HS_RISC_V_OPCODES_INSN_DECLARE(c_sq);
HS_RISC_V_OPCODES_INSN_DECLARE(c_sw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_fsw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_sd);
//象限1
HS_RISC_V_OPCODES_INSN_DECLARE(c_nop);
HS_RISC_V_OPCODES_INSN_DECLARE(c_addi);
HS_RISC_V_OPCODES_INSN_DECLARE(c_jal);
HS_RISC_V_OPCODES_INSN_DECLARE(c_addiw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_li);
HS_RISC_V_OPCODES_INSN_DECLARE(c_addi16sp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_lui);
HS_RISC_V_OPCODES_INSN_DECLARE(c_srli);
HS_RISC_V_OPCODES_INSN_DECLARE(c_srli64);
HS_RISC_V_OPCODES_INSN_DECLARE(c_srai);
HS_RISC_V_OPCODES_INSN_DECLARE(c_srai64);
HS_RISC_V_OPCODES_INSN_DECLARE(c_andi);
HS_RISC_V_OPCODES_INSN_DECLARE(c_sub);
HS_RISC_V_OPCODES_INSN_DECLARE(c_xor);
HS_RISC_V_OPCODES_INSN_DECLARE(c_or);
HS_RISC_V_OPCODES_INSN_DECLARE(c_and);
HS_RISC_V_OPCODES_INSN_DECLARE(c_subw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_addw);
HS_RISC_V_OPCODES_INSN_DECLARE(c_j);
HS_RISC_V_OPCODES_INSN_DECLARE(c_beqz);
HS_RISC_V_OPCODES_INSN_DECLARE(c_bnez);
//象限2
HS_RISC_V_OPCODES_INSN_DECLARE(c_slli);
HS_RISC_V_OPCODES_INSN_DECLARE(c_slli64);
HS_RISC_V_OPCODES_INSN_DECLARE(c_fldsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_lqsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_lwsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_flwsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_ldsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_jr);
HS_RISC_V_OPCODES_INSN_DECLARE(c_mv);
HS_RISC_V_OPCODES_INSN_DECLARE(c_ebreak);
HS_RISC_V_OPCODES_INSN_DECLARE(c_jalr);
HS_RISC_V_OPCODES_INSN_DECLARE(c_add);
HS_RISC_V_OPCODES_INSN_DECLARE(c_fsdsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_sqsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_swsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_fswsp);
HS_RISC_V_OPCODES_INSN_DECLARE(c_sdsp);

/*
 * Zifencei
 */
HS_RISC_V_OPCODES_INSN_DECLARE(fence_i);


struct hs_risc_v_opcodes_csr;
typedef struct hs_risc_v_opcodes_csr hs_risc_v_opcodes_csr_t;

struct  hs_risc_v_opcodes_csr
{
    const char *name;   /**< CSR名称 */
    uint16_t    addr;  /**< CSR地址 */
};

/** \brief 声明要使用的CSR
 *
 *
 */
#ifdef __cplusplus
#define HS_RISC_V_OPCODES_CSR_DECLARE(NAME) \
extern "C" const hs_risc_v_opcodes_csr_t hs_risc_v_opcodes_csr_##NAME
#else
#define HS_RISC_V_OPCODES_CSR_DECLARE(NAME) \
extern const hs_risc_v_opcodes_csr_t hs_risc_v_opcodes_csr_##NAME
#endif

/** \brief 获取CSR的名称
 *
 *
 */
#define HS_RISC_V_OPCODES_CSR_NAME(NAME) (hs_risc_v_opcodes_csr_##NAME)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __HS_RISC_V_OPCODES_H__

