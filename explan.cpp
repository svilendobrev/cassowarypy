
PyObject * explanation_list( ExCLError * self) { 
     PyObject * list = PyList_New(0);
        PyList_Append( list, PyString_FromString( self->description().c_str() ));
     const ConstraintSet * e = self->explanation();
     int size = e ? e->size() : 0;
        if (size)
            for (ConstraintSet::const_iterator i=e->begin(); i!=e->end(); ++i) {
                const Constraint* c = *i;
                PyList_Append( list, 
                    SWIG_NewPointerObj( (void *) c, SWIGTYPE_p_Constraint, 1) );
            }
        return list;
}

