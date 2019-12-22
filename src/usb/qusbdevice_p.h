#ifndef QUSBDEVICE_P_H
#define QUSBDEVICE_P_H

#include "qusbdevice.h"
#include <private/qobject_p.h>
#include <QThread>

#include <libusb-1.0/libusb.h>

QT_BEGIN_NAMESPACE

class QUsbEventsThread : public QThread
{
public:
    void run();

    libusb_context *m_ctx;
};

class QUsbTransferPrivate;

class QUsbDevicePrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QUsbDevice)
    friend QUsbTransferPrivate;

public:
    QUsbDevicePrivate();
    ~QUsbDevicePrivate();

    /**
   * @brief Print error code to qWarning
   *
   * @param error_code
   */
    void printUsbError(int error_code) const;

    libusb_device **m_devs; /**< libusb device ptr to ptr */
    libusb_device_handle *m_devHandle; /**< libusb device handle ptr */
    libusb_context *m_ctx; /**< libusb context */

    QUsbEventsThread *m_events;
};

QT_END_NAMESPACE

#endif
