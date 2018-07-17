    if (runTime.writeTime())
    {
        volVectorField gradd(fvc::grad(d));
        volScalarField lap(fvc::laplacian(gamma,d));

        volScalarField graddx
        (
            IOobject
            (
                "graddx",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            gradd.component(vector::X)
        );

        volScalarField graddy
        (
            IOobject
            (
                "graddy",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            gradd.component(vector::Y)
        );

        volScalarField graddz
        (
            IOobject
            (
                "graddz",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            gradd.component(vector::Z)
        );

        volScalarField lapd
        (
            IOobject
            (
                "lapd",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            lap
        );

        volVectorField gradgraddx(fvc::grad(graddx));
        volVectorField gradgraddy(fvc::grad(graddy));
        volVectorField gradgraddz(fvc::grad(graddz));
	volTensorField hessianMatrix
        (
	    IOobject
	    (
	        "hessianMatrix",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	    ),
	    mesh,
	    dimensionedTensor
            (
	     "hess",
	     dimensionSet(0,-1,0,0,0,0,0),
	     tensor::zero
	    )
	 );
            

	hessianMatrix.replace(0, gradgraddx.component(vector::X));
	hessianMatrix.replace(1, gradgraddy.component(vector::X));
	hessianMatrix.replace(2, gradgraddz.component(vector::X));
	hessianMatrix.replace(3, gradgraddx.component(vector::Y));
	hessianMatrix.replace(4, gradgraddy.component(vector::Y));
	hessianMatrix.replace(5, gradgraddz.component(vector::Y));
	hessianMatrix.replace(6, gradgraddx.component(vector::Z));
	hessianMatrix.replace(7, gradgraddy.component(vector::Z));
	hessianMatrix.replace(8, gradgraddz.component(vector::Z));
        volScalarField hess_det
        (
            IOobject
            (
                "hess_det",
                runTime.timeName(),
                mesh,
                IOobject::NO_READ,
                IOobject::AUTO_WRITE
            ),
            det(hessianMatrix)
        );
        runTime.write();
    }
