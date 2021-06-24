//* Alan Chavez
//* Boise State University
//* 24 June 2021

#pragma once

#include "Kernel.h"
#include "Function.h"
#include "DerivativeMaterialInterface.h"

class NewCoefDiffusion : public Kernel
{
public:
  static InputParameters validParams();

  NewCoefDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const MaterialProperty<Real> & _m;
};
