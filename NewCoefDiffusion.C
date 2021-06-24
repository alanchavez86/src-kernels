//* Alan Chavez
//* Boise State University
//* 24 June 2021

#include "NewCoefDiffusion.h"

registerMooseObject("diffusion", NewCoefDiffusion);

InputParameters
NewCoefDiffusion::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addClassDescription("Kernel for Magnetic Potential using Magnetization Saturation");
  params.addRequiredParam<MaterialPropertyName>("m", "Base name of the Magnetization Saturation defined in a DertivativeParsedMaterial");
  return params;
}

NewCoefDiffusion::NewCoefDiffusion(const InputParameters & parameters)
  : Kernel(parameters),
    _m(getMaterialProperty<std::vector<Real>>("m")) // Magnetization Saturation Vector
{
}

Real
NewCoefDiffusion::computeQpResidual()
{
  return _grad_test[_i][_qp] * -_grad_u[_qp] - _m[_qp]*grad_test[_i][_qp];
}

Real
NewCoefDiffusion::computeQpJacobian()
{
  return _grad_test[_i][_qp] * -_grad_phi[_j][_qp] - _m[_qp]*grad_test[_i][_qp];
}
