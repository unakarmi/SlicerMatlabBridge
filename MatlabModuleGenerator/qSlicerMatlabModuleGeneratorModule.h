/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

#ifndef __qSlicerMatlabModuleGeneratorModule_h
#define __qSlicerMatlabModuleGeneratorModule_h

// SlicerQt includes
#include "qSlicerLoadableModule.h"

#include "qSlicerMatlabModuleGeneratorModuleExport.h"

class qSlicerMatlabModuleGeneratorModulePrivate;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_MATLABMODULEGENERATOR_EXPORT
qSlicerMatlabModuleGeneratorModule
  : public qSlicerLoadableModule
{
  Q_OBJECT
#ifdef Slicer_HAVE_QT5
  Q_PLUGIN_METADATA(IID "org.slicer.modules.loadable.qSlicerLoadableModule/1.0");
#endif  
  Q_INTERFACES(qSlicerLoadableModule);

public:

  typedef qSlicerLoadableModule Superclass;
  explicit qSlicerMatlabModuleGeneratorModule(QObject *parent=0);
  virtual ~qSlicerMatlabModuleGeneratorModule();

  qSlicerGetTitleMacro(QTMODULE_TITLE);

  virtual QString helpText()const;
  virtual QString acknowledgementText()const;
  virtual QStringList contributors()const;

  virtual QIcon icon()const;

  virtual QStringList categories()const;
  virtual QStringList dependencies() const;

protected:

  /// Get location of the Matlab executable.
  /// Search order:
  /// \li Slicer.ini application settings
  /// \li SLICER_MATLAB_EXECUTABLE_PATH environment variable
  /// \li Path or App Paths
  /// \li Hardcoded default location
  QString getMatlabExecutablePath() const;

  /// Initialize the module. Register the volumes reader/writer
  virtual void setup();

  /// Create and return the widget representation associated to this module
  virtual qSlicerAbstractModuleRepresentation * createWidgetRepresentation();

  /// Create and return the logic associated to this module
  virtual vtkMRMLAbstractLogic* createLogic();

protected:
  QScopedPointer<qSlicerMatlabModuleGeneratorModulePrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerMatlabModuleGeneratorModule);
  Q_DISABLE_COPY(qSlicerMatlabModuleGeneratorModule);

};

#endif
