//
// Created by zj on 2025/7/25.
//

#include "InstructionFactory.h"
#include "comparisons/If_icmp.h"
#include "comparisons/if_acmp.h"
#include "constants/Ipush.h"
#include "constants/Ldc.h"
#include "control/Goto.h"
#include "control/Return.h"
#include "conversions/I2x.h"
#include "loads/Aload.h"
#include "loads/Dload.h"
#include "loads/Fload.h"
#include "loads/Iload.h"
#include "loads/XAload.h"
#include "math/Add.h"
#include "math/Iinc.h"
#include "references/Checkcast.hpp"
#include "references/Getfield.hpp"
#include "references/Getstatic.hpp"
#include "references/New.h"
#include "references/Putfield.hpp"
#include "references/Putstatic.hpp"
#include "stack/Dup.h"
#include "stack/Pop.h"
#include "stack/Swap.h"
#include "stores/Astore.h"
#include "stores/Dstore.h"
#include "stores/Fstore.h"
#include "stores/Istore.h"
#include "stores/Lstore.h"
#include "stores/XAstore.h"

Instruction* InstructionFactory::createInstruction(u1 opcode) {
  switch (opcode) {
  case ICONST_M1:{
    auto *val =new IConstM1();
    val->setName("ICONST_M1");
    return val;
  }
  case ICONST_0:{
    auto *val =new IConst0();
    val->setName("ICONST_0");
    return val;
  }
  case ICONST_1:   {auto *val = new IConst1        ();val->setName("IConst1        "); return val;}
  case ICONST_2:   {auto *val = new IConst2        ();val->setName("IConst2        "); return val;}
  case ICONST_3:   {auto *val = new IConst3        ();val->setName("IConst3        "); return val;}
  case ICONST_4:   {auto *val = new IConst4        ();val->setName("IConst4        "); return val;}
  case ICONST_5:   {auto *val = new IConst5        ();val->setName("IConst5        "); return val;}
  case ACONST_NULL:{auto *val = new AConstNULL     ();val->setName("AConstNULL     "); return val;}
  case LCONST_0:   {auto *val = new LConst0        ();val->setName("LConst0        "); return val;}
  case LCONST_1:   {auto *val = new LConst1        ();val->setName("LConst1        "); return val;}
  case FCONST_0:   {auto *val = new FConst0        ();val->setName("FConst0        "); return val;}
  case FCONST_1:   {auto *val = new FConst1        ();val->setName("FConst1        "); return val;}
  case FCONST_2:   {auto *val = new FConst2        ();val->setName("FConst2        "); return val;}
  case DCONST_0:   {auto *val = new DConst0        ();val->setName("DConst0        "); return val;}
  case DCONST_1:   {auto *val = new DConst1        ();val->setName("DConst1        "); return val;}
  case BIPUSH:     {auto *val = new Bipush         ();val->setName("Bipush         "); return val;}
  case SIPUSH:     {auto *val = new Sipush         ();val->setName("Sipush         "); return val;}
  case LDC:        {auto *val = new Ldc            ();val->setName("ldc            "); return val;}
  case LDC_W:	     {auto *val = new Ldc_w          ();val->setName("ldc_w          "); return val;}
  case LDC2_W:     {auto *val = new Ldc2_w         ();val->setName("ldc2_w         "); return val;}
  case ALOAD:      {auto *val = new Aload          ();val->setName("Aload          "); return val;}
  case ALOAD_0:    {auto *val = new Aload_0        ();val->setName("Aload_0        "); return val;}
  case ALOAD_1:    {auto *val = new Aload_1        ();val->setName("Aload_1        "); return val;}
  case ALOAD_2:    {auto *val = new Aload_2        ();val->setName("Aload_2        "); return val;}
  case ALOAD_3:    {auto *val = new Aload_3        ();val->setName("Aload_3        "); return val;}
  case DLOAD:      {auto *val = new Dload          ();val->setName("Dload          "); return val;}
  case DLOAD_0:    {auto *val = new Dload_0        ();val->setName("Dload_0        "); return val;}
  case DLOAD_1:    {auto *val = new Dload_1        ();val->setName("Dload_1        "); return val;}
  case DLOAD_2:    {auto *val = new Dload_2        ();val->setName("Dload_2        "); return val;}
  case DLOAD_3:    {auto *val = new Dload_3        ();val->setName("Dload_3        "); return val;}
  case FLOAD:      {auto *val = new Fload          ();val->setName("Fload          "); return val;}
  case FLOAD_0:    {auto *val = new Fload_0        ();val->setName("Fload_0        "); return val;}
  case FLOAD_1:    {auto *val = new Fload_1        ();val->setName("Fload_1        "); return val;}
  case FLOAD_2:    {auto *val = new Fload_2        ();val->setName("Fload_2        "); return val;}
  case FLOAD_3:    {auto *val = new Fload_3        ();val->setName("Fload_3        "); return val;}
  case ILOAD:      {auto *val = new Iload          ();val->setName("Iload          "); return val;}
  case ILOAD_0:    {auto *val = new Iload_0        ();val->setName("Iload_0        "); return val;}
  case ILOAD_1:    {auto *val = new Iload_1        ();val->setName("Iload_1        "); return val;}
  case ILOAD_2:    {auto *val = new Iload_2        ();val->setName("Iload_2        "); return val;}
  case ILOAD_3:    {auto *val = new Iload_3        ();val->setName("Iload_3        "); return val;}
  case AALOAD:     {auto *val = new AAload         ();val->setName("AAload         "); return val;}
  case BALOAD:     {auto *val = new BAload         ();val->setName("BAload         "); return val;}
  case CALOAD:     {auto *val = new CAload         ();val->setName("CAload         "); return val;}
  case DALOAD:     {auto *val = new DAload         ();val->setName("DAload         "); return val;}
  case FALOAD:     {auto *val = new FAload         ();val->setName("FAload         "); return val;}
  case IALOAD:     {auto *val = new IAload         ();val->setName("IAload         "); return val;}
  case LALOAD:     {auto *val = new LAload         ();val->setName("LAload         "); return val;}
  case SALOAD:     {auto *val = new SAload         ();val->setName("SAload         "); return val;}

  case ISTORE           :{auto *val = new Istore          ();val->setName("Istore         "); return val;}
  case LSTORE           :{auto *val = new Lstore          ();val->setName("Lstore         "); return val;}
  case FSTORE           :{auto *val = new Fstore          ();val->setName("Fstore         "); return val;}
  case DSTORE           :{auto *val = new Dstore          ();val->setName("Dstore         "); return val;}
  case ISTORE_0         :{auto *val = new Istore_0        ();val->setName("Istore_0       "); return val;}
  case ISTORE_1         :{auto *val = new Istore_1        ();val->setName("Istore_1       "); return val;}
  case ISTORE_2         :{auto *val = new Istore_2        ();val->setName("Istore_2       "); return val;}
  case ISTORE_3         :{auto *val = new Istore_3        ();val->setName("Istore_3       "); return val;}
  case LSTORE_0         :{auto *val = new Lstore_0        ();val->setName("Lstore_0       "); return val;}
  case LSTORE_1         :{auto *val = new Lstore_1        ();val->setName("Lstore_1       "); return val;}
  case LSTORE_2         :{auto *val = new Lstore_2        ();val->setName("Lstore_2       "); return val;}
  case LSTORE_3         :{auto *val = new Lstore_3        ();val->setName("Lstore_3       "); return val;}
  case FSTORE_0         :{auto *val = new Fstore_0        ();val->setName("Fstore_0       "); return val;}
  case FSTORE_1         :{auto *val = new Fstore_1        ();val->setName("Fstore_1       "); return val;}
  case FSTORE_2         :{auto *val = new Fstore_2        ();val->setName("Fstore_2       "); return val;}
  case FSTORE_3         :{auto *val = new Fstore_3        ();val->setName("Fstore_3       "); return val;}
  case DSTORE_0         :{auto *val = new Dstore_0        ();val->setName("Dstore_0       "); return val;}
  case DSTORE_1         :{auto *val = new Dstore_1        ();val->setName("Dstore_1       "); return val;}
  case DSTORE_2         :{auto *val = new Dstore_2        ();val->setName("Dstore_2       "); return val;}
  case DSTORE_3         :{auto *val = new Dstore_3        ();val->setName("Dstore_3       "); return val;}
  case ASTORE_0         :{auto *val = new Astore_0        ();val->setName("Astore_0       "); return val;}
  case ASTORE_1         :{auto *val = new Astore_1        ();val->setName("Astore_1       "); return val;}
  case ASTORE_2         :{auto *val = new Astore_2        ();val->setName("Astore_2       "); return val;}
  case ASTORE_3         :{auto *val = new Astore_3        ();val->setName("Astore_3       "); return val;}
  case IASTORE          :{auto *val = new IAstore         ();val->setName("IAstore        "); return val;}
  case LASTORE          :{auto *val = new LAstore         ();val->setName("LAstore        "); return val;}
  case FASTORE          :{auto *val = new FAstore         ();val->setName("FAstore        "); return val;}
  case DASTORE          :{auto *val = new DAstore         ();val->setName("DAstore        "); return val;}
  case AASTORE          :{auto *val = new AAstore         ();val->setName("AAstore        "); return val;}
  case POP              :{auto *val = new Pop             ();val->setName("Pop            "); return val;}
  case DUP              :{auto *val = new Dup             ();val->setName("Dup            "); return val;}
  case DUP_X1           :{auto *val = new Dupx1           ();val->setName("Dupx1          "); return val;}
  case DUP_X2           :{auto *val = new Dupx2           ();val->setName("Dupx2          "); return val;}
  case DUP2             :{auto *val = new Dup2            ();val->setName("Dup2           "); return val;}
  case DUP2_X1          :{auto *val = new Dup2x1          ();val->setName("Dup2x1         "); return val;}
  case DUP2_X2          :{auto *val = new Dup2x2          ();val->setName("Dup2x2         "); return val;}
  case SWAP             :{auto *val = new Swap            ();val->setName("Swap           "); return val;}
  case IADD             :{auto *val = new Iadd            ();val->setName("Iadd           "); return val;}
  case LADD             :{auto *val = new Ladd            ();val->setName("Ladd           "); return val;}
  case FADD             :{auto *val = new Fadd            ();val->setName("Fadd           "); return val;}
  case DADD             :{auto *val = new Dadd            ();val->setName("Dadd           "); return val;}
  case IINC             :{auto *val = new Iinc            ();val->setName("Iinc           "); return val;}
  case I2D              :{auto *val = new I2d             ();val->setName("I2d            "); return val;}
  case IF_ICMPEQ        :{auto *val = new If_icmpeq       ();val->setName("If_icmpeq      "); return val;}
  case IF_ICMPNE        :{auto *val = new If_icmpne       ();val->setName("If_icmpne      "); return val;}
  case IF_ICMPLT        :{auto *val = new If_icmplt       ();val->setName("If_icmplt      "); return val;}
  case IF_ICMPGE        :{auto *val = new If_icmpge       ();val->setName("If_icmpge      "); return val;}
  case IF_ICMPGT        :{auto *val = new If_icmpgt       ();val->setName("If_icmpgt      "); return val;}
  case IF_ICMPLE        :{auto *val = new If_icmple       ();val->setName("If_icmple      "); return val;}
  case IF_ACMPEQ        :{auto *val = new If_acmpeq       ();val->setName("If_acmpeq      "); return val;}
  case IF_ACMPNE        :{auto *val = new If_acmpne       ();val->setName("If_acmpne      "); return val;}
  case GOTO             :{auto *val = new Goto            ();val->setName("Goto           "); return val;}
  case IRETURN          :{auto *val = new IReturn         ();val->setName("IReturn        "); return val;}
  case ARETURN          :{auto *val = new AReturn         ();val->setName("AReturn        "); return val;}
  case RETURN           :{auto *val = new Return          ();val->setName("Return         "); return val;}
  case GETSTATIC        :{auto *val = new Getstatic       ();val->setName("Getstatic      "); return val;}
  case PUTSTATIC        :{auto *val = new Putstatic       ();val->setName("Putstatic      "); return val;}
  case GETFIELD         :{auto *val = new Getfield        ();val->setName("Getfield       "); return val;}
  case PUTFIELD         :{auto *val = new Putfield        ();val->setName("Putfield       "); return val;}
//  case INVOKEVIRTUAL    :{auto *val = new Invokevirtual   ();val->setName("Invokevirtual  "); return val;}
//  case INVOKESPECIAL    :{auto *val = new Invokespecial   ();val->setName("Invokespecial  "); return val;}
//  case INVOKESTATIC     :{auto *val = new Invokestatic    ();val->setName("Invokestatic   "); return val;}
//  case INVOKEINTERFACE  :{auto *val = new Invokeinterface ();val->setName("Invokeinterface"); return val;}
//  case INVOKEDYNAMIC    :{auto *val = new Invokedynamic   ();val->setName("Invokedynamic  "); return val;}
  case NEW              :{auto *val = new New             ();val->setName("New            "); return val;}
//  case NEWARRAY         :{auto *val = new Newarray        ();val->setName("Newarray       "); return val;}
//  case ANEWARRAY        :{auto *val = new Anewarray       ();val->setName("Anewarray      "); return val;}
//  case ARRAYLENGTH      :{auto *val = new Arraylength     ();val->setName("Arraylength    "); return val;}
//  case ATHROW           :{auto *val = new Athrow          ();val->setName("Athrow         "); return val;}
  case CHECKCAST        :{auto *val = new Checkcast       ();val->setName("Checkcast      "); return val;}
  default: {
    return new Nop();
  }
  }
}