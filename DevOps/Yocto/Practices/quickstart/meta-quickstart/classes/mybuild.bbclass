# Declares a task named "build".
# Note: Bitbake will add the "do_" prefix to the function name, if it was not given.
addtask build

# The "mybuild_do_" prefix is for following the conventions: classname_do_functionname for a task in a class.
mybuild_do_build () {
    echo "running mybuild_do_build."
}

# Make the build function available to users of this class.
# The function, which will execute the task "build", is "mybuild_do_build" 
# because the base name matches (i.e., do_build).
EXPORT_FUNCTIONS do_build