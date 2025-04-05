cmake_minimum_required(VERSION 3.30)
project(StreetSimulator)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(StreetSimulator main.cpp
        StreetSimulatorApp.cpp
        StreetSimulatorApp.h
        StreetSimulatorSFMLView.cpp
        StreetSimulatorSFMLView.h
        StreetSimulatorView.h
        StreetSimulatorPresenter.cpp
        StreetSimulatorPresenter.h
        GridType.h
        WorldMapGridProvider.cpp
        WorldMapGridProvider.h
        RoadOption.h
        Direction.h
        Field.h
        Point.h
        Direction.h
        FieldValue.h
        GlobalConstants.h
        RoadGenerator.cpp
        RoadGenerator.h
        Car.cpp
        Car.h
        DirectionMapper.h
        FieldHelper.h
        Speed.h
        DirectionException.h
        DirectionDelta.h
        RelativeDirection.h
        Light.h
        CollisionDetector.cpp
        CollisionDetector.h
        EdgeCollisionHelper.h
        Intersection.h
        Intersection.cpp
        LightsIntersection.cpp
        LightsIntersection.h
        LightsManager.cpp
        LightsManager.h
        UncontrolledIntersection.cpp
        UncontrolledIntersection.h
        VectorHelper.h
)

target_link_libraries(StreetSimulator PRIVATE SFML::Graphics)