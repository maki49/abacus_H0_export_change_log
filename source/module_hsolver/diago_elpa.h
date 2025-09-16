#ifndef DIAGOELPA_H
#define DIAGOELPA_H

#include "diagh.h"
#include "module_basis/module_ao/parallel_orbitals.h"

namespace hsolver
{

    template<typename T>
    class DiagoElpa : public DiagH<T>
    {
    private:
        using Real = typename GetTypeReal<T>::type;

    public:
        void diag(hamilt::Hamilt<T>* phm_in, psi::Psi<T>& psi, Real* eigenvalue_in) override;

    static int DecomposedState;

  private:
#ifdef __MPI
    bool ifElpaHandle(const bool& newIteration, const bool& ifNSCF);
#endif
};

template <typename T>
int DiagoElpa<T>::DecomposedState = 0;

} // namespace hsolver

#endif
