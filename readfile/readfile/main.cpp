//
//  main.cpp
//  readfile
//
//  Created by Виткина Анна on 18.04.2023.
// pid_t pid = 21266;
//unsigned long addr = 0x1013ed000;


#include <iostream>
#include <mach/mach.h>
#include <mach/mach_vm.h>

    int main() {
    pid_t pid = 21266;
    mach_port_t task;
    kern_return_t kr;
    
    // get task port
    kr = task_for_pid(mach_task_self(), pid, &task);
    if (kr != KERN_SUCCESS) {
        std::cerr << "Failed to get task port" << std::endl;
        return -1;
    }
    // read memory
    unsigned long addr = 0x1013ed000;
    uint32_t size = 4;
    uint64_t data = 0;
    kr = mach_vm_read(task, (mach_vm_address_t)addr, size, (vm_offset_t*)&data, (mach_msg_type_number_t*)&size);
    if (kr != KERN_SUCCESS) {
        std::cerr << "Failed to read memory" << std::endl;
        return -1;
    }
    std::cout << "Data at address " << std::hex << addr << " is " << std::dec << data << std::endl;

        return 0;
    }
