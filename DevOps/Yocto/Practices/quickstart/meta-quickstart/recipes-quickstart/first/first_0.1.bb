DESCRIPTION = "I am the first recipe"

# Revision number (should be updated after each major change)
PR = "r1"

# Overrides the empty global build task from base.bbclass.
do_build () {
    echo "first: some shell script running as build"
}