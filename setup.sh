UTM_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Library paths
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UTM_ROOT}/tmUtil
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UTM_ROOT}/tmGrammar
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UTM_ROOT}/tmTable
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UTM_ROOT}/tmXsd
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UTM_ROOT}/tmEventSetup

# Python package/module paths
export PYTHONPATH=${PYTHONPATH}:${UTM_ROOT}/tmTable
export PYTHONPATH=${PYTHONPATH}:${UTM_ROOT}/tmGrammar
export PYTHONPATH=${PYTHONPATH}:${UTM_ROOT}/tmEventSetup

# Environmentals
export UTM_ROOT=${UTM_ROOT}
export UTM_XSD_DIR=${UTM_ROOT}/tmXsd
export LC_ALL="en_US.UTF-8" # set locale required by xsd command
