import pandas

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
