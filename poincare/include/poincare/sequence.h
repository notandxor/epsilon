#ifndef POINCARE_SEQUENCE_H
#define POINCARE_SEQUENCE_H

#include <poincare/layout_engine.h>
#include <poincare/static_hierarchy.h>
#include <poincare/evaluation_engine.h>

namespace Poincare {

class Sequence : public StaticHierarchy<3>  {
  using StaticHierarchy<3>::StaticHierarchy;
private:
  constexpr static float k_maxNumberOfSteps = 10000.0f;
  ExpressionLayout * privateCreateLayout(FloatDisplayMode floatDisplayMode, ComplexFormat complexFormat) const override;
  Evaluation<float> * privateEvaluate(SinglePrecision p, Context& context, AngleUnit angleUnit) const override { return templatedEvaluate<float>(context, angleUnit); }
  Evaluation<double> * privateEvaluate(DoublePrecision p, Context& context, AngleUnit angleUnit) const override { return templatedEvaluate<double>(context, angleUnit); }
 template<typename T> Evaluation<T> * templatedEvaluate(Context& context, AngleUnit angleUnit) const;
  virtual ExpressionLayout * createSequenceLayoutWithArgumentLayouts(ExpressionLayout * subscriptLayout, ExpressionLayout * superscriptLayout, ExpressionLayout * argumentLayout) const = 0;
  virtual int emptySequenceValue() const = 0;
  virtual Evaluation<float> * evaluateWithNextTerm(Evaluation<float> * a, Evaluation<float> * b) const = 0;
  virtual Evaluation<double> * evaluateWithNextTerm(Evaluation<double> * a, Evaluation<double> * b) const = 0;
};

}

#endif
