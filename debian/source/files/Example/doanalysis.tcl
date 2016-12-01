#
# Note: companion script "makemibd.tcl" must be run first
#
proc doanalysis {} {
#
# Clean up from last analysis
#
    exec rm -rf q4
#
# Polygenic analysis
#
    load phenotypes gaw10.phen
    trait q4
    covariate age sex age*sex
    polygenic -screen
#
# Point to ibd and mibd directories for linkage analyses
#
    ibddir gaw10ibd
    mibddir gaw10mibd
#
# Twopoint analysis
#
    twopoint
#
# Multipoint analysis
#
    chromosome 9 10
    interval 5
    finemap 1 0.5
    multipoint 2 1
    return ""
}
