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

#include <sys/types.h>
#include "l2mcd.h"
#include <linux/filter.h>
#include "mld_vlan_db.h"
#include "l2mcd_mld_utils.h"
#include "l2mcd_mld_port.h"
#include "l2mcd_mcast_co.h"
#include <sys/ioctl.h>
#include "l2mcd_dbsync.h"
#include "l2mcd_portdb.h"

extern  mld_vlan_db_t mld_vlan_db;
extern struct list *snooping_enabled_vlans[MCAST_AFI_MAX];
#define L2MCD_PBUF_SIZE 4000
char pbuf[L2MCD_PBUF_SIZE];

void l2mcd_dump_port_vlan_bm()
{

}

void l2mcd_dump_portdb_tree(int id)
{

}
void l2mcd_dump_portdb()
{
    l2mcd_dump_portdb_tree(0);
    l2mcd_dump_portdb_tree(1);
}


void l2mcd_mcgrp_dump_source_list (MCGRP_CLASS   *mcgrp,
                             MCGRP_MBRSHP  *mcgrp_mbrshp)
{

}


void l2mcd_clear_snooping(int vid)
{

}

void l2mcd_clear_snooping_stats(int vid)
{

}
void l2mcd_clr_snooping(int vid)
{
    l2mcd_clear_snooping(vid);
}
void l2mcd_clr_snooping_stats(int vid)
{
    l2mcd_clear_snooping_stats(vid);
}
void l2mcd_dump_groups(int vid, int flag)
{

}

void l2mcd_dump_vdb_port_list(int vid, int tree_id)
{

}
void l2mcd_dump_vdb_ports(int vid)
{

}
void l2mcd_dump_ve_portdb_tree(void)
{

}

void l2mcd_dump_vdb_brief(int vid)
{

}

void l2mcd_dump_vdb_stats(int vid)
{
}

void l2mcd_dump_snooping_vlans()
{
}

void l2mcd_print_global_var()
{
}
void l2mcd_print_vars()
{

}
void l2mcd_dump_custom(int id)
{

}

void l2mcd_dump_cfg(int vid)
{

}


void l2mcd_set_loglevel(int level)
{
}
void l2mcd_set_loglevel_w(int level)
{
}

void dump_mcgrpl3if(int vid)
{
}
