/*
 * Copyright 2019 Broadcom.  The term “Broadcom” refers to Broadcom Inc. and/or
 * its subsidiaries.

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __L2MCD_MLD_PORT__
#define __L2MCD_MLD_PORT__

#include "mld_vlan_db.h"

/* Flag manipulation macros. */
#define CHECK_FLAG(V,F)      ((V) & (F))
#define SET_FLAG(V,F)        (V) = (V) | (F)
#define UNSET_FLAG(V,F)      (V) = (V) & ~(F)
#define COMPARE(A,B)  strncmp(A, B, strlen(A))

#define ONE_SEC_MILLISECOND (1000)
#define HALFSEC_MILLISEC    (500)
#define MSEC2SECROUND(a)  (((a % ONE_SEC_MILLISECOND) > HALFSEC_MILLISEC) ? \
                        ((a / ONE_SEC_MILLISECOND) + 1):(a / ONE_SEC_MILLISECOND))
/* Macros to increment/decrement mld vlan count */
#define MLD_SNP_VLAN_COUNT_INC(x, vlan_node, afi) {(x)->mld_snp_vlan_count++; mld_vlan_add_list(vlan_node, afi);}
#define MLD_SNP_VLAN_COUNT_DEC(x, vlan_node, afi) {(x)->mld_snp_vlan_count--; mld_vlan_del_list(vlan_node, afi);}

typedef enum {
    MLD_IFTYPE_LOOPBACK = 1,
    MLD_IFTYPE_MGMT,
    MLD_IFTYPE_L3PHY,
    MLD_IFTYPE_L3SVI,
    MLD_IFTYPE_L3TUN,
    MLD_IFTYPE_L3TRUNK,
    MLD_IFTYPE_OTHER,
} mld_l3_if_type_t;
#endif //__L2MCD_MLD_PORT__
