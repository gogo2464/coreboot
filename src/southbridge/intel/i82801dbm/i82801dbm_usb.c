#include <console/console.h>
#include <device/device.h>
#include <device/pci.h>
#include <device/pci_ids.h>
#include <device/pci_ops.h>
#include "i82801dbm.h"

static void usb_init(struct device *dev)
{
	uint32_t cmd;

#if 0
	printk_debug("USB: Setting up controller.. ");
	cmd = pci_read_config32(dev, PCI_COMMAND);
	pci_write_config32(dev, PCI_COMMAND, 
		cmd | PCI_COMMAND_IO | PCI_COMMAND_MEMORY | 
		PCI_COMMAND_MASTER | PCI_COMMAND_INVALIDATE);


	printk_debug("done.\n");
#endif

}

static struct device_operations usb_ops  = {
	.read_resources   = pci_dev_read_resources,
	.set_resources    = pci_dev_set_resources,
	.enable_resources = pci_dev_enable_resources,
	.init             = usb_init,
	.scan_bus         = 0,
	.enable           = i82801dbm_enable,
};

static struct pci_driver usb_driver_1 __pci_driver = {
	.ops    = &usb_ops,
	.vendor = PCI_VENDOR_ID_INTEL,
	.device = PCI_DEVICE_ID_INTEL_82801ER_1D0,
};
static struct pci_driver usb_driver_2 __pci_driver = {
        .ops    = &usb_ops,
        .vendor = PCI_VENDOR_ID_INTEL,
        .device = PCI_DEVICE_ID_INTEL_82801ER_1D1,
};
static struct pci_driver usb_driver_3 __pci_driver = {
        .ops    = &usb_ops,
        .vendor = PCI_VENDOR_ID_INTEL,
        .device = PCI_DEVICE_ID_INTEL_82801ER_1D2,
};
static struct pci_driver usb_driver_4 __pci_driver = {
        .ops    = &usb_ops,
        .vendor = PCI_VENDOR_ID_INTEL,
        .device = PCI_DEVICE_ID_INTEL_82801ER_1D3,
};

