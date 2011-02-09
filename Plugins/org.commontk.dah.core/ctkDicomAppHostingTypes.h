/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#include <QString>
#include <QList>

#ifndef CTKDICOMAPPHOSTINGTYPES_H
#define CTKDICOMAPPHOSTINGTYPES_H

#ifdef ERROR
#error Try to reorder include files (this one first)\
 or write #undef ERROR before including this header.\
 Cause of this problem may be dcmimage.h, which indirectly\
 includes windows.h.
#endif

/**
  * \brief Typedefs and classes defined in the interfaces of DICOM Supplement 118.
  *
  */
namespace ctkDicomAppHosting {

  enum State {
    IDLE,
    INPROGRESS,
    COMPLETED,
    SUSPENDED,
    CANCELED,
    EXIT
  };

  enum StatusType {
    INFORMATION,
    WARNING,
    ERROR,
    FATALERROR
  };

  struct Status {
    StatusType statusType;
    QString codingSchemeDesignator;
    QString codeValue;
    QString codeMeaning;
  };

  struct ObjectLocator {
    QString locator;
    QString source;
    QString transferSyntax;
    qint64 length;
    qint64 offset;
    QString URI;
  };

  struct ObjectDescriptor {
    QString descriptorUUID;
    QString mimeType;
    QString classUID;
    QString transferSyntaxUID;
    QString modality;
  };

  typedef QList<ObjectDescriptor> ArrayOfObjectDescriptors;

  struct Series {
    QString seriesUID;
    ArrayOfObjectDescriptors objectDescriptors;
  };

  struct Study {
    QString studyUID;
    ArrayOfObjectDescriptors objectDescriptors;
    QList<Series> series;
  };

  struct Patient {
    QString name;
    QString id;
    QString assigningAuthority;
    QString sex;
    QString birthDate;
    ArrayOfObjectDescriptors objectDescriptors;
    QList<Study> studies;
  };

  struct AvailableData {
    ArrayOfObjectDescriptors objectDescriptors;
    QList<Patient> patients;
  };

}

#endif // CTKDICOMAPPHOSTINGTYPES
