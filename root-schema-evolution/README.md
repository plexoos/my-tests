# Usage

To run the test do:

    cd my-tests/root-evolu
    mkdir build && cd build
    cmake ../
    cmake --build .
    write_A8
    # Inspect TTree in evolu.root
    read_A8_via_A9
    read_A8_via_B3


# References

- "Support For Significant Evolutions of the User Data ModelIn ROOT Files," -
  https://lss.fnal.gov/cgi-bin/find_paper.pl?conf-09-720

- "ROOT Data Model Evolution," - https://root.cern.ch/root/SchemaEvolution.pdf 


# Fix for STAR picoDst

A possible pragma to fix star-picoDst backward compatibility issue

    #pragma read sourceClass="StPicoTrack" version="[1]" targetClass="StPicoTrack" \
       source="char mCharge;" target="mNHitsFit" code="{ mNHitsFit = mNHitsFit*onfile.mCharge; }"
