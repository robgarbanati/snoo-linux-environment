/* linux/include/asm-arm/arch-w90p910/nand.h
 *
 * (c) 2004 Simtec Electronics
 *  Ben Dooks <ben@simtec.co.uk>
 *
 * W90P910 - NAND device controller platfrom_device info
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Changelog:
 *	23-Sep-2004 BJD  Created file
*/

/* struct w90p910_nand_set
 *
 * define an set of one or more nand chips registered with an unique mtd
 *
 * nr_chips	 = number of chips in this set
 * nr_partitions = number of partitions pointed to be partitoons (or zero)
 * name		 = name of set (optional)
 * nr_map	 = map for low-layer logical to physical chip numbers (option)
 * partitions	 = mtd partition list
*/

struct W90XXXX_nand_set {
	int			nr_chips;
	int			nr_partitions;
	char			*name;
	int			*nr_map;
	struct mtd_partition	*partitions;
};

struct W90XXXX_platform_nand {
	/* timing information for controller, all times in nanoseconds */

	int	tacls;	/* time for active CLE/ALE to nWE/nOE */
	int	twrph0;	/* active time for nWE/nOE */
	int	twrph1;	/* time for release CLE/ALE from nWE/nOE inactive */

	int			nr_sets;
	struct W90XXXX_nand_set *sets;

	void			(*select_chip)(struct W90XXXX_nand_set *,
					       int chip);
};

