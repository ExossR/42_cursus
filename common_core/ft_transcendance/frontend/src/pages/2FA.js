import { useState } from "react";
import useUser from "../hooks/useUserStorage";
import CheckValidQrCode from "../components/settings/CheckValidQrCode";
import { useNavigate } from "react-router-dom";
import './2FA.css';
import './loading.css'

const TwoFactorAuth = () => {
    const user = useUser("user");
    const [error, setError] = useState(null);
    const [loading, setLoading] = useState(false);
    const navigate = useNavigate();

    const handle2FAValidation = (checkStatusCode) => {
        if (checkStatusCode) {
            setLoading(true);
            user.set("2FAValid", true);
            setTimeout(() => navigate("/home"), 1000);
        } else {
            setError("Code invalide");
            setTimeout(() => setError(null), 2000);
        }
    }

    return (
         <div className="container2FA">
	    <div className="authContainer">
            {loading ? (
                <div className="loading-2FA">
      		<p className="loading-2FA-text" >Authentication in progress...</p>
    		</div>
            ) : (
                <div>
                    <h1>Two-Factor autentification</h1>
                    <p>Enter the 6-digit code generated by your application to confirm your action.</p>
                    <CheckValidQrCode checkStatusCode={handle2FAValidation} />
                    {error && <div className="text-danger">{error}</div>}
                </div>
            )}
        </div>
     </div>
    );
}

export default TwoFactorAuth;