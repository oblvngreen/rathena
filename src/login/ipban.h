/**
 * @file ipban.h
 * Module purpose is to read configuration for login-server and handle accounts,
 *  and also to synchronize all login interfaces: loginchrif, loginclif, logincnslif.
 * Licensed under GNU GPL.
 *  For more information, see LICENCE in the main folder.
 * @author Athena Dev Teams < r15k
 * @author rAthena Dev Team
 */

#ifndef __IPBAN_H_INCLUDED__
#define __IPBAN_H_INCLUDED__

#include "../common/cbasetypes.h"

/**
 * Check if ip is in active bans list
 * @param ip: ipv4 ip to check if ban
 * @return true found or error, false not in list
 */
bool ipban_check(uint32 ip);

/**
 * Log failed attempt
 *  Also ban user if too much fail attemp is made
 * @param ip: ipv4 ip to record the failure
 */
void ipban_log(uint32 ip);

/**
 * Read configuration options
 * @param key: config keyword
 * @param value: config value for keyword
 * @return true success, false config not complete or serv already running
 */
bool ipban_config_read(const char* key, const char* value);

/**
 * Initialise the module.
 * Launched at login-serv start, create db or other long scope variable here.
 */
void ipban_init(void);

/**
 * Destroy the module.
 * Launched at login-serv end, cleanup db connection or other thing here
 */
void ipban_final(void);

#endif // __IPBAN_H_INCLUDED__
