/*
 * Copyright (c) 2015 BalaBit
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */

#include "stats/stats-counter.h"
#include "stats/stats-cluster.h"
#include "stats/stats-registry.h"

static void
_reset_counter(StatsCluster *sc, gint type, StatsCounterItem *counter, gpointer user_data)
{
  stats_counter_set(counter, 0);
}

void
stats_reset_counters(void)
{
  stats_lock();
  stats_foreach_counter(_reset_counter, NULL);
  stats_unlock();
}

