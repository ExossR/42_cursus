import { Link } from 'react-router-dom';
import { Container, Paper, styled } from '@mui/material';

export const StyledLink = styled(Link)({
    textDecoration: 'none',
    color: 'inherit',
    cursor: 'default',
});

export const StyledPaper = styled(Paper)(({ theme }) => ({
    padding: theme.spacing(2),
    ...theme.typography.body2,
    textAlign: 'center',
    color: theme.palette.text.secondary,
}));

export const StyledContainer = styled(Container)({
    // height: '100vh',
    display: 'flex',
    justifyContent: 'center',
    alignItems: 'center',
});

export const StyledDisplay = styled('div')(({ theme }) => ({
    boxSizing: 'border-box',
    display: 'flex',
    alignItems: 'left',
    margin: '0 0 0 0',
    padding: '20px',
    border: '4px solid #333',
    minHeight: '30px',
    borderRadius: '20px',
    color: '#999',
    background: '#000',
    fontFamily: 'Pixel, Arial, Helvetica, sans-serif',
    fontSize: '0.8rem',

    // Si la fenêtre d'affichage est plus large que 1024px (typiquement un écran d'ordinateur en plein écran)
    '@media (min-width: 1024px)': {
        width: '80%', // Utilisez cette largeur si la fenêtre est en plein écran
    },

    // Si la fenêtre d'affichage est moins large que 1024px (typiquement un écran d'ordinateur non plein écran ou un appareil mobile)
    '@media (max-width: 1023px)': {
        width: '98%', // Utilisez cette largeur si la fenêtre n'est pas en plein écran
    },
}));

export const StyledAsideRigt = styled('aside')(({theme}) => ({
    display: 'flex',
    flexDirection: 'column',
    gap: '30px',
}));

export const StyledAsideLeft = styled('aside')(({theme}) => ({
    display: 'flex',
    flexDirection: 'column',
    flexWrap: 'wrap',
    placeContent: 'end',
    gap: '30px',
}));
