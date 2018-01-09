import pandas


def make_plotly_data( csv_filename, legend_format_string=None ):
    """
    Example:

       legend_format_string='Trace {: 3d}'
    """

    dataframe_csv = pandas.read_csv(csv_filename, sep='\s*,\s*', engine='python', index_col=0)

    index_col_values = dataframe_csv.index.values.tolist()
    head_row_values = dataframe_csv.columns.values.tolist()

    data = []
    entry_counter = 1


    for head_value in head_row_values:
        trace_name = head_value if legend_format_string is None else legend_format_string.format(entry_counter)
        trace = {
                 'x': index_col_values,
                 'y': dataframe_csv[head_value].tolist(),
                 'type': 'bar',
                 'name': trace_name
                }
        data.append( trace )
        entry_counter += 1

    return data



def make_plotly_obj( csv_filename ):

    dataframe_csv = pandas.read_csv(csv_filename, sep='\s*,\s*', engine='python', index_col=0)

    index_column_values = dataframe_csv.index.values.tolist()
    head_row_values = dataframe_csv.columns.values.tolist()

    data = []

    for head_value in head_row_values:
        trace = {
                 'x': index_column_values,
                 'y': dataframe_csv[head_value].tolist(),
                 'type': 'bar',
                 'name': head_value
                }
        data.append( trace )

    return {
        'data': data,
        'layout': {
            'barmode': 'group',
            'hovermode': 'closest',
            'legend': {
                'x': 0,
                'xanchor': 'left',
                'y': 1,
                'yanchor': 'bottom'
            }
        }
    }
