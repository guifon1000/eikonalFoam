    Info<< "Reading field d\n" << endl;

    volScalarField d
    (
        IOobject
        (
            "d",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );


    Info<< "Reading Gamma\n" << endl;
    dimensionedScalar gamma
    (
	"gamma",
	dimensionSet(0,1,0,0, 0,0,0),
	transportProperties.lookup("gamma")
    );
    Info<< "Reading Alpha\n" << endl;
    dimensionedScalar alpha
    (
	"alpha",
	dimensionSet(0,0,0,0, 0,0,0),
	transportProperties.lookup("alpha")
    );
