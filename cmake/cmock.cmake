# Author: Tofik Sonono
# This cmock wrapper allows for creating mocks of header files easily
# This script requires Ruby >=v2.0.0 in your path
# Mocks will be placed in ${FCFS_ROOT}/mocks (atleast when using vscode cmake integration)

set(MOCK_SCRIPT ${FCFS_CMOCK_DIR}/lib/cmock.rb)

macro(create_mock header_path)
    execute_process(COMMAND ruby ${MOCK_SCRIPT} ${header_path} -o${FCFS_ROOT}/cmock_config.yml
                    OUTPUT_VARIABLE output)
    message(${output})
endmacro(create_mock header_path)
