inherit mybuild

confbuild_do_configure () {
  echo "Running configbuild_do_configure."
}

addtask do_configure before do_build

EXPORT_FUNCTIONS do_configure
