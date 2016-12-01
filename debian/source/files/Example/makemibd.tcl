proc makemibd {} {
#
# Purpose: Makes ibd and mibd files for chromosome 9 and 10 in subdirectories
#
#
# Remove old directories (if any) and make new ones
#
    exec rm -rf gaw10ibd
    exec rm -rf gaw10mibd
    exec mkdir gaw10ibd
    exec mkdir gaw10mibd
    ibddir gaw10ibd
    mibddir gaw10mibd
#
# Make ibd files...simple case where all genotypes are known
#
    load pedigree gaw10.ped
    load marker mrk9
    ibd
    load marker mrk10
    ibd
#
# Make mibd files
#
    load marker mrk9
    load map map9
    mibd 1
    load marker mrk10
    load map map10
    mibd 1
}
